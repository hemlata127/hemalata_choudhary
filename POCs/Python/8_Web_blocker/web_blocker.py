#import the required modules
from time import *;
from datetime import datetime as dt;

#definition of the required variables
#path of the host file o windows
host_path = "C:\\Windows\\System32\\drivers\\etc\\hosts";
#IP address that the website to be blocked should be redirected to
redirect = "127.0.0.1";
#list of websites to be blocked
websites = ["https://facebook.com", "www.facebook.com"];

#setting up the infinite loop
while(True):
	#code for working hours
	if dt(dt.now().year, dt.now().month, dt.now().day, 9) < dt.now() < dt(dt.now().year, dt.now().month, dt.now().day, 13):
		fileptr = open(host_path, 'r+');
		content = fileptr.read();
		for website in websites:
			if website in content:
				pass;
			else:
				fileptr.write(redirect+"    "+website+"\n");
	#code for fun hours
	else:
		fileptr = open(host_path, 'r+');
		content = fileptr.readlines();
		fileptr.seek(0);
		for line in content:
			if not any(website in line for website in websites):
				fileptr.write(line);
		fileptr.truncate();
	sleep(5);
