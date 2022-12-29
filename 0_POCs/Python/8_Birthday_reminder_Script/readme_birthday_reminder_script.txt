Script Name: Birthday reminder script
Description:
	The script reads the list of contact details from an excel file. It compares the birthdate for each contact record and send an email with birthday wish to the email address associated with the record. The script is scheduled to run at 12.00 a.m every day. It can be added to the list of OS start up scripts to start running on system startup or reboot
Modules Used: pandas, datetime, smtplib, email.mime.text, schedule, time