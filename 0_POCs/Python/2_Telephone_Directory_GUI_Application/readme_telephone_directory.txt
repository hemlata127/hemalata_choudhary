Application Name: Telephone Directory Graphical User Application
Modules used: Tkinter, mysql.connector, smtplib, email.mime.text
Description: 
	A user interface to telephone directory system is presented. The UI provides options to Create new contact, search contact, exit application and reset the UI.
	1. Create new contact - Selecting this option presents appropriate UI to enter the contact details like first name, last name, email address, phone number and address. If the details already exist in database (searched by phone number), proper message appears, else the details are added to the database.
	2. Search Contact - Add a phone number to search the contact. If no matching record is found, proper message appears, else matching record details are displayed. User is presented an option to send email. The user can provide subject and body and user can send the email. Confirmation message appears on success.
	3. Exit application - Quits the application
	4. Reset - Resets the UI
	
Initialisation script: Creates the required database and database tables.