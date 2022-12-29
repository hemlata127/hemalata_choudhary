from tkinter import *
import mysql.connector;
import smtplib;
from email.mime.text import MIMEText;

class TelephoneDirectory:
    myconnection = None;
    mycursor = None;
    mywindow = None;
    myframe = None;
    def __init__(self):
        #create a DB connection
        self.myconnection = mysql.connector.connect(
		host = "localhost",
		user = "anwesha",
		password = "xxxxxx"
		);

        #create cursor to execute queries
        self.mycursor = self.myconnection.cursor();

        #create main window
        self.mywindow = Tk();
        self.mywindow.title("Telephone Directory");
        self.mywindow.state("zoomed");
    
    def CreateFrame(self):
        self.myframe = LabelFrame(self.mywindow);
        self.myframe.grid(row = 4, column = 0, rowspan = 25, columnspan=25);

    def CreateWindowControls(self):
        TelephoneDirectory.CreateFrame(self);
        Label(self.mywindow, text = "Telephone directory management system").grid(row = 0, column = 0);
        Button(self.mywindow, text = "Create New Contact", height = 1, width = 20, command = lambda:TelephoneDirectory.CreateFrameControlsNewRecord(self)).grid(row = 3, column = 0);
        Button(self.mywindow, text = "Search Contact", height = 1, width = 20, command = lambda:TelephoneDirectory.CreateFrameControlsSearchRecord(self)).grid(row = 3, column = 1);
        Button(self.mywindow, text = "Reset", height = 1, width = 20, command = lambda:TelephoneDirectory.ResetWindow(self)).grid(row = 3, column = 2);
        Button(self.mywindow, text = "Exit Application", height = 1, width = 20, command = TelephoneDirectory.ExitApplication).grid(row = 3, column = 3);
        self.mywindow.mainloop();

    def CreateFrameControlsNewRecord(self):
        TelephoneDirectory.ResetWindow(self);
        FirstName = StringVar();
        LastName = StringVar();
        PhoneNo = StringVar();
        EmailId = StringVar();
        Address = StringVar();
        FirstNameLabel = Label(self.myframe, width = 15, anchor = "e", text = "First Name: ").grid(row = 4, column = 0);
        FirstNameField = Entry(self.myframe, textvariable = FirstName);
        FirstNameField.grid(row = 4, column = 1)
        LastNameLabel = Label(self.myframe, width = 15, anchor = "e", text = "Last Name: ").grid(row = 5, column = 0);
        LastNameField = Entry(self.myframe, textvariable = LastName);
        LastNameField.grid(row = 5, column = 1);
        PhoneNoLabel = Label(self.myframe, width = 15, anchor = "e", text = "Phone Number: ").grid(row = 6, column = 0);
        PhoneNoField = Entry(self.myframe, textvariable = PhoneNo);
        PhoneNoField.grid(row = 6, column = 1);
        EmailIdLabel = Label(self.myframe, width = 15, anchor = "e", text = "Email Id: ").grid(row = 7, column = 0);
        EmailIdField = Entry(self.myframe, textvariable = EmailId);
        EmailIdField.grid(row = 7, column = 1);
        AddressLabel = Label(self.myframe, width = 15, anchor = "e", text = "Address: ").grid(row = 8, column = 0);
        AddressField = Entry(self.myframe, textvariable = Address);
        AddressField.grid(row = 8, column = 1);
        SubmitButtonMessage = Label(self.myframe, text = "");
        SubmitButtonMessage.grid(row = 12, column = 0);
        SubmitButton = Button(self.myframe, height = 1, width = 10, text = "Submit", command = lambda:TelephoneDirectory.InsertNewRecord(self, FirstName.get(), LastName.get(), PhoneNo.get(), EmailId.get(), Address.get(), SubmitButtonMessage)).grid(row = 10, column = 0);
        ClearButton = Button(self.myframe, height = 1, width = 10, text = "Clear", command = lambda:TelephoneDirectory.ClearFrameControlRecords(FirstNameField, LastNameField, PhoneNoField, EmailIdField, AddressField, SubmitButtonMessage)).grid(row = 10, column = 1);
                
    def ClearFrameControlRecords(FirstNameField, LastNameField, PhoneNoField, EmailIdField, AddressField, SubmitButtonMessage):
        FirstNameField.delete(0,"end");
        LastNameField.delete(0,END);
        PhoneNoField.delete(0,END);
        EmailIdField.delete(0,END);
        AddressField.delete(0,END);
        SubmitButtonMessage.config(text = "");

    def InsertNewRecord(self, FirstName, LastName, PhoneNo, EmailId, Address, SubmitButtonMessage):
        search_existing_records_query = "select * from telephonedirectory.contacts where PhoneNumber = %s";
        self.mycursor.execute(search_existing_records_query, (PhoneNo,));
        result = self.mycursor.fetchall();
        if(self.mycursor.rowcount == 0):
            insert_query = "insert into telephonedirectory.contacts (FirstName, LastName, PhoneNumber, EmailId, Address) Values (%s, %s, %s, %s, %s)";
            val = (FirstName, LastName, PhoneNo, EmailId, Address);
            self.mycursor.execute(insert_query, val);
            self.myconnection.commit();
            SubmitButtonMessage.config(text = "New record is added successfully!!!");
        elif(result[0][3] == PhoneNo):
            SubmitButtonMessage.config(text = "Record with this phone number already exists!!");

    def CreateFrameControlsSearchRecord(self):
        PhoneNo = StringVar();
        TelephoneDirectory.ResetWindow(self);
        Label(self.myframe, text = "Enter phone number: ", width = 50, anchor = "w").grid(row = 4, column = 0);
        PhoneNumberField = Entry(self.myframe, textvariable=PhoneNo);
        PhoneNumberField.grid(row = 4, column = 1);
        MessageLabel = Label(self.myframe, text = "", width = 50, anchor = "w");
        MessageLabel.grid(row = 6, column = 0);
        FirstNameLabel = Label(self.myframe, text = "", width = 50, anchor = "w");
        FirstNameLabel.grid(row = 7, column = 0);
        LastNameLabel = Label(self.myframe, text = "", width = 50, anchor = "w");
        LastNameLabel.grid(row = 8, column = 0);
        PhoneNumberLabel = Label(self.myframe, text = "", width = 50, anchor = "w");
        PhoneNumberLabel.grid(row = 9, column = 0);
        EmailIdLabel = Label(self.myframe, text = "", width = 50, anchor = "w");
        EmailIdLabel.grid(row = 10, column = 0);
        AddressLabel = Label(self.myframe, text = "", width = 50, anchor = "w");
        AddressLabel.grid(row = 11, column = 0);
        Button(self.myframe, text = "Search", height = 1, width = 10, command = lambda:TelephoneDirectory.SearchExistingRecord(self, PhoneNo.get(), MessageLabel, FirstNameLabel, LastNameLabel, PhoneNumberLabel, EmailIdLabel, AddressLabel)).grid(row = 5, column = 0);
        Button(self.myframe, text = "Clear", height = 1, width = 10, command = lambda:TelephoneDirectory.ClearSearchControls(self, PhoneNumberField, MessageLabel, FirstNameLabel, LastNameLabel, PhoneNumberLabel, EmailIdLabel, AddressLabel)).grid(row = 5, column = 1);

    def SearchExistingRecord(self, PhoneNo, MessageLabel, FirstNameLabel, LastNameLabel, PhoneNumberLabel, EmailIdLabel, AddressLabel):
        search_query = "select * from telephonedirectory.contacts where PhoneNumber = %s";
        self.mycursor.execute(search_query, (PhoneNo,));
        result = self.mycursor.fetchall();
        if(self.mycursor.rowcount == 0):
            Label(self.myframe, text = "No record with this phone number found.").grid(row = 6, column = 0);
        else:
            FirstName = result[0][1];
            LastName = result[0][2];
            PhoneNumber = result[0][3];
            EmailId = result[0][4];
            Address = result[0][5];
            MessageLabel.config(text = "Following are the details of the record with entered phone number: ");
            FirstNameLabel.config(text="First Name: " + FirstName);
            LastNameLabel.config(text="Last Name: " + LastName);
            PhoneNumberLabel.config(text="Phone Number: " + PhoneNumber);
            EmailIdLabel.config(text="EmailId: " + EmailId);
            AddressLabel.config(text="Address: " + Address);
            Button(self.myframe, height = 1, width = 10, text = "Send Email", command = lambda:TelephoneDirectory.SendEmailControls(self, EmailId)).grid(row = 12, column = 0);

    def SendEmailControls(self, ToEmailId):
        FromAddress = "hemlata127@gmail.com";
        ToAddress = ToEmailId;
        Subject = StringVar();
        FromAddressLabel = Label(self.myframe, text = "From Address:", width = 50, anchor = "w");
        FromAddressLabel.grid(row = 13, column = 0);
        FromAddressField = Entry(self.myframe, width = 20);
        FromAddressField.grid(row = 13, column = 1);
        FromAddressField.insert(0,FromAddress);
        ToAddressLabel = Label(self.myframe, text = "To Address: ", width = 50, anchor = "w");
        ToAddressLabel.grid(row = 14, column = 0);
        ToAddressField = Entry(self.myframe);
        ToAddressField.grid(row = 14, column = 1);
        ToAddressField.insert(0,ToAddress);
        SubjectLabel = Label(self.myframe, text = "Subject: ", width = 50, anchor = "w");
        SubjectLabel.grid(row = 15, column = 0);
        SubjectField = Entry(self.myframe, textvariable=Subject);
        SubjectField.grid(row = 15, column = 1);
        BodyLabel = Label(self.myframe, text = "Body: ", width = 50, anchor = "w");
        BodyLabel.grid(row = 16, column = 0);
        BodyTextArea = Text(self.myframe, width = 15, height = 10);
        BodyTextArea.grid(row = 16, column = 1);
        SendMessage = Label(self.myframe, text = "");
        SendMessage.grid(row = 18, column = 0);
        SendButton = Button(self.myframe, height = 1, width = 10, text = "Send", command = lambda:TelephoneDirectory.SendMail(self, FromAddress, ToAddress, Subject.get(), BodyTextArea, SendMessage));
        SendButton.grid(row = 17, column = 1);
        
                
    def SendMail(self, FromAddress, ToAddress, Subject, BodyTextArea, SendMessage):
        body = BodyTextArea.get(1.0,"end-1c");
        msg = MIMEText(body, _subtype='plain', _charset='UTF-8');
        msg['Subject'] = Subject;
        msg['From'] = FromAddress;
        msg['To'] = ToAddress;
        try:
            smtpobj = smtplib.SMTP('smtp.gmail.com',587);
            smtpobj.starttls();
            smtpobj.login('hemlata127@gmail.com','acfuybahpculessh');
            smtpobj.send_message(msg);
            smtpobj.quit();
            SendMessage.config(text = "Mail sent successfully!!!");
        except:
            SendMessage.config(text = "There was an error sending email!!!");

    def ClearSearchControls(self, PhoneNumberField, MessageLabel, FirstNameLabel, LastNameLabel, PhoneNumberLabel, EmailIdLabel, AddressLabel):
        PhoneNumberField.delete(0,"end");
        MessageLabel.config(text = "");
        FirstNameLabel.config(text = "");
        LastNameLabel.config(text = "");
        PhoneNumberLabel.config(text = "");
        EmailIdLabel.config(text = "");
        AddressLabel.config(text = "");

    def ResetWindow(self):
        for x in self.myframe.winfo_children():
            x.destroy();

    def ExitApplication():
        exit();

    def __del__(self):
        self.myconnection.close();

def Main():
    td = TelephoneDirectory();
    td.CreateWindowControls();

if(__name__ == "__main__"):
    Main();
