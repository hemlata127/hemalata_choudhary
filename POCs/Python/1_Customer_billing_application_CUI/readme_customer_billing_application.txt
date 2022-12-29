Application: Customer Billing Application
Type of Application: Command User Interface
Modules used: mysql.connector, datetime
Description:
	The application presents the user with four options:
	1. Process new order - User must enter phone number. If the number exeists in the database, welcome message appears and user is asked to provide the cart details. Order is processed, total amount calculated and order summary entered in the database. If the phone number does not exeist, customer is asked to provide the details like First name, last name, email address and address. The details are added in the database and proceeds with order processing
	2. Search last customer order - User must provide the phone number and the last order details associated with customer with this phone number are displayed. If phone number does not exist or there are no order details for this customer, proper message appears
	3. Display customer details - User must provide the phone number. The customer details are searched in database and displayed. If there are not details associated with entered phone number, appropriate message appears
	4. Exit application - Quits the application
	
Initialisation script: Creates the required database, database tables and also adds the static data to the appropriate table.