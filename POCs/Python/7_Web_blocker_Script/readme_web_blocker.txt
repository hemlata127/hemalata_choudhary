Script Name: Website Blocker
Description: This is a python application that will block a list of websites during the specified time period
	If you want to block a website, we must add an entry of the website in hosts file and redirect it to local host IP. This script adds such entries to the hosts file for all the websites that needs to be blocked.
	9.00 a.m to 17.00 p.m is identified as working hours. During this time the script adds the required entries to the hosts file. During rest of the time, the entries are removed from the hosts file. The script is executed every 5 seconds. It is added to the OS start script list so that it starts executing on machine startup or reboot.
Modules used: time, datetime, file handling functions
Methods/attributes used:
	sys.sleep()
	datetime.datetime.now()
	open() - opens specified file in specified mode and returns file pointer
	fptr.read() - reads the entire file into a single string
	fptr.readlines() - reads the contents of file as list of lines
	fptr.seek() - moves the current file offset to specified position from start of file, current position or end of file
	fptr.truncate() - truncates the file to the specified size, if no size is specified, current position is considered
	fptr.write() - writes the specified string to the file
Running the script at system startup:
	Linux: add the required entry to the crontab
	Windows: Add it to the task scheduler