Script Name: Process Logger
Description: This script accepts directory name and email address from the user as command line arguments.
	In the entered directory, it creates the log file which contains information about the currently running processes. The log file is then sent to the entered email address
Modules used: sys, os, time, psutil, smtplib, urllib.request
Methods used:
	sys.argv() - to get the list of command line arguments
	psutil.process_iter() - to iterate over running processes
	os.path.dir() - checks if specified file is a directory
	os.mkdir() - to create a directory
	os.path.isabs() - checks if file path is absolute path
	fptr = open() - opens a file
	fptr.write() - writes to the already opened file
	fptr.close() - closes a file
	urllib.request.urlopen() - opens the specified url and returns True is the URL is opened successfully
	server = smtplib.SMTP_SSL() - opens secure connection to mailserver (SMTP server)
	server.ehlo() - sends hello to connected server
	server.login(username,password) - logs in to the mail server
	server.sendmail(sent_from,email_address,email_text);
	server.close() - close the connection
	
	