Script Name: Website Blocker
Description: This is a python application that will block a list of websites during the specified time period
			If you want to block a website, we must add an entry of the website in hosts file and redirect it to local host IP.
			This script adds such entries to the hosts file for all the websites that needs to be bloked.
			9.00 a.m to 17.00 p.m is identified as working hours. During this time the script add the required entries to the hosts file. During rest of the time, the entries are removed from the hosts file.
Modules used: time, datetime, file handling functions
Running the script at system startup:
	Linux: add the required entry to the crontab
	Windows: Add it to the task scheduler