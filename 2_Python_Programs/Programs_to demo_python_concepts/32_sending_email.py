#import smtp module
import smtplib;
#create smtp object
sobj = smtplib.SMTP("gmail.com",587);
#create login session
sobj.login("hemlata127@gmail.com","xxxx");
#create variables for from, to and message
from_address = "hemlata127@gmail.com";
to_address = ["hemlata127@gmail.com"];
message = """
From: %s
To: %s
Subject: Hello from python
This is a test email
"""%(from_address,to_address);
#send mail
sobj.sendmail(from_address,to_address,message);
#close the session
sobj.quit();