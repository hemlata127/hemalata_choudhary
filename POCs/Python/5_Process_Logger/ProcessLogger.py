'''
Automation script which accept directory name and mail id from user and create log
file in that directory which contains information of running processes as its name, PID,
Username. After creating log file send that log file to the specified mail.
Usage : ProcInfoLog.py Demo hemlata127@gmail.com
Demo is name of Directory.
hemlata127@gmail.com is the mail id.
'''
import sys;
import psutil;
import os;
import urllib.request;
import smtplib;
import time;

def ProcInfo(dirname):
	l1 = [];
	for i in psutil.process_iter():
		l1.append(i.as_dict(attrs=['name','pid','username']));
		
	if os.path.isdir(dirname) == False:
		os.mkdir(dirname,mode=777);
		
	if os.path.isabs(dirname) == False:
		dirname = os.path.abspath(dirname);
	
	filename = dirname+"\log.txt";
	fd1 = open(filename,'w');
	
	fd1.write("Process information");
	
	for i in l1:
		fd1.write("\n"+"-"*60);
		fd1.write("\n"+str(i));
	
	fd1.close();
	
	return filename;
	
def is_connected():
	try:
		urllib.request.urlopen("http://google.com",timeout=1)
		return True;
	except Exception as E:
		return False;
		
def MailSender(username,password,logfilename,to_address):
	sent_from = username;
	email_address = to_address;
	fd1 = open(logfilename,'r');
	email_text = fd1.read();
	fd1.close();
		
	try:
		server = smtplib.SMTP_SSL('smtp.gmail.com',465);
		server.ehlo();
		server.login(username,password);
		server.sendmail(sent_from,email_address,email_text);
		server.close();
		
		print("Mail sent successfully");
	
	except Exception as E:
		print("Unable to send email",E);


def main():
	print("Automation script by Hemalata Choudhary");
	print("Application name: ",sys.argv[0]);
	if len(sys.argv)!=3:
		print("Invalid number of arguments. Use -h or -u options for help or usage");
	
	if sys.argv[1] == '-h':
		print("Script to display process information");
		
	if sys.argv[1] == '-u':
		print("python ScriptName");
	
	try:
		username = 'hemlata127@gmail.com';
		password = 'xxxxxxxx';
		logfilename = ProcInfo(sys.argv[1]);
		to_address = sys.argv[2];
				
		connected = is_connected();
				
		if connected:
			starttime = time.time();
			MailSender(username,password,logfilename,to_address);
			endtime = time.time();
			print("Took %s time to send the email"%(endtime-starttime));
		else:
			print("No internet connection");
	
	except Exception as E:
		print("Error: Invalid input",E);

if __name__ == "__main__":
	main();