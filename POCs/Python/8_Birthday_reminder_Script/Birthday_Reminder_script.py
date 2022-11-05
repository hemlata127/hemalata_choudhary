import pandas as pd;
from datetime import datetime as dt;
import smtplib;
from email.mime.text import MIMEText;
import schedule;
import time;

def SendMail(firstname, lastname, toaddress):
    print("Sending email to {} {} on emailid {}".format(firstname,lastname,toaddress));
    fromaddress = "hemlata127@gmail.com";
    password = "xxxxxxx";
    sendername = "Hemalata Choudhary";
    subject = "Happy Birthday!!!";
    body = "Dear {} {},\n\nWish you a very Happy Birthday.\nHave a wonderful year ahead :)\n\nThanks and Regards,\n{}".format(firstname,lastname,sendername);
    msg = MIMEText(body, _subtype='plain', _charset='UTF-8');
    msg['Subject'] = subject;
    msg['From'] = fromaddress;
    msg['To'] = toaddress;
    try:
        smtpobj = smtplib.SMTP('smtp.gmail.com',587);
        smtpobj.starttls();
        smtpobj.login(fromaddress,password);
        smtpobj.send_message(msg);
        smtpobj.quit();
        print("Mail sent successfully!!!");
    except:
        print("There was an error sending email!!!");

def ReadContactDetails(filename):
    dataframe1 = pd.read_excel(filename);
    row = 0;
    #find and store current month and day
    currentmonth = dt.now().month;
    currentday = dt.now().day;
    #run the for loop for each row from the dataframe
    for x in range(0,len(dataframe1)):
        birthmonth = (dataframe1.loc[x][2]).month;
        birthday = (dataframe1.loc[x][2]).day;
        if((birthmonth == currentmonth) and (birthday == currentday)):
            firstname = dataframe1.loc[x][0];
            lastname = dataframe1.loc[x][1];
            emailid = dataframe1.loc[x][3];
            SendMail(firstname,lastname,emailid);
        row = row+1;

def Main():
    filename="Contact_details.xlsx";
    #call the function ReadContactDetails every day at midnight
    schedule.every().day.at("00:00").do(ReadContactDetails,filename);
    while True:
        schedule.run_pending();
        time.sleep(1);

if(__name__ == "__main__"):
    Main();