from tkinter import *;
import mysql.connector;
from datetime import datetime;

class StoreManagement:
	mainwindow = None;
	mycursor = None;
	myconnection = None;
	
	def __init__(self):
		#create a DB connection
		self.myconnection = mysql.connector.connect(
		host = "localhost",
		user = "anwesha",
		password = "Eastonia@01"
		);	

		self.mycursor = self.myconnection.cursor();	

		#create the main window, maximize it, add a title
		self.mainwindow = Tk();
		self.mainwindow.state("zoomed");
		self.mainwindow.title("Customer Billing Application");

	def CreateWindow(self):		
		#Display welcome message
		welcome_message = Label(self.mainwindow, text = "Welcome to Venus Store!!", justify=CENTER);
		welcome_message.grid(row = 0, column = 0);
		
		#Display message to select an option
		action_message = Label(self.mainwindow, text = "Please select an action:", justify=LEFT);
		action_message.grid(row = 2, column = 0);			
		
		#Create and add the option buttons to the TOP frame
		option1 = Button(self.mainwindow, text = "Process new order", command = self.ProcessNewOrder).grid(row = 3, column = 0);
		option2 = Button(self.mainwindow, text = "Search last order").grid(row = 3, column = 1);
		option3 = Button(self.mainwindow, text = "Display customer details").grid(row = 3, column = 2);
		option4 = Button(self.mainwindow, text = "Exit Application", command = StoreManagement.ExitApplication).grid(row = 3, column = 3);
		option5 = Button(self.mainwindow, text = "Reset", command = StoreManagement.ResetWindow).grid(row = 3, column = 4);
				
		self.mainwindow.mainloop();

	def ProcessNewOrder(self):
		phone = StringVar();
		phonenumberlabel = Label(self.mainwindow, text = "Please enter the phone number: ", justify=LEFT).grid(row = 7, column = 0);
		phonenumberfield = Entry(self.mainwindow, textvariable = phone).grid(row = 7, column = 1);		
		submitbutton = Button(self.mainwindow, text = "Submit", command = lambda:StoreManagement.CheckPhone(self, phone.get())).grid(row = 7, column = 2);

	def CheckPhone(self, phone):
		select_query = "select * from storemanagementsystem.customers where phonenumber = %s";
		self.mycursor.execute(select_query,(phone,));
		myresult = self.mycursor.fetchall();
		print(myresult);
		if len(myresult) == 0:
			customerid = StoreManagement.AcceptNewCustomerDetails(self, phone);
			StoreManagement.GenerateNewOrder(self, customerid);
		else:
			s1 = "Welcome {} {}".format(list(myresult)[0][1], list(myresult)[0][2]);
			existingcustomermessage = Label(text = s1, justify=LEFT).grid(row = 8, column = 0);
			customerid = list(myresult)[0][0];
			StoreManagement.GenerateNewOrder(self, customerid);
				

	def AcceptNewCustomerDetails(self, phone):
		#Label for the first time visitor
		first_name = StringVar();
		last_name = StringVar();
		email_id = StringVar();
		customer_address = StringVar();
		label1 = Label(self.mainwindow, text = "You have visited the store for the first time").grid(row = 8, column = 0);
		label2 = Label(self.mainwindow, text = "Please provide us some details to help us serve you better!").grid(row = 9, column = 0);
		FirstNameLabel = Label(self.mainwindow, text = "First Name: ").grid(row = 10, column = 0);
		FirstNameTextfield = Entry(self.mainwindow, textvariable=first_name).grid(row = 10, column = 1);
		LastNameLabel = Label(self.mainwindow, text = "Last Name: ").grid(row = 11, column = 0);
		LastNameTextfield = Entry(self.mainwindow, textvariable=last_name).grid(row = 11, column = 1);
		EmailId = Label(self.mainwindow, text = "Email Address: ").grid(row = 12, column = 0);
		EmailIdTextfield = Entry(self.mainwindow, textvariable=email_id).grid(row = 12, column = 1);
		Address = Label(self.mainwindow, text = "Address: ").grid(row = 13, column = 0);
		AddressTextfield = Entry(self.mainwindow, textvariable=customer_address).grid(row = 13, column = 1);
		Update = Button(self.mainwindow, text = "Update", command = lambda:StoreManagement.InsertNewCustomerDetails(self, first_name.get(), last_name.get(), phone, email_id.get(), customer_address.get())).grid(row = 14, column = 0);

	def InsertNewCustomerDetails(self, first_name, last_name, phone, email_id, customer_address):		
		now = datetime.now();
		formatted_date = now.strftime('%Y-%m-%d %H:%M:%S');
		
		sql_insert_query = """INSERT INTO storemanagementsystem.customers (FirstName, LastName, PhoneNumber, EmailId, LastStoreVisit, Address) VALUES (%s, %s, %s, %s, %s, %s)""";
		val = (first_name, last_name, phone, email_id, formatted_date, customer_address);
		self.mycursor.execute(sql_insert_query, val);
		self.myconnection.commit();

		sql_select_query = """select customerid from storemanagementsystem.customers where phonenumber = %s"""
		self.mycursor.execute(sql_select_query, (phone,));
		myresult = self.mycursor.fetchall();
		customerid = list(myresult)[0][0];
		print(customerid);
		return customerid;

	def GenerateNewOrder(self, customerid):
		SelectItemsMessage = Label(text="Select the items from the following list: ", justify=LEFT).grid(row = 11, column = 0);
		self.mycursor.execute("select * from storemanagement.items");
		result = self.mycursor.fetchall();	
		print(result);
		i = 1;
		TableHeader1 = Label(text = "ITEM").grid(row = 13, column = 0);
		TableHeader2 = Label(text = "DISCOUNT").grid(row = 13, column = 1);
		TableHeader3 = Label(text = "QUANTITY").grid(row = 13, column = 2);
		TableHeader4 = Label(text = "ITEM TOTAL").grid(row = 13, column = 3);
		for x in result:
			Item = Checkbutton(self.mainwindow, text = x[1], onvalue=1, justify=LEFT).grid(row = 13+i, column = 0);
			Discount = Label(text = x[3]).grid(row = 13+i, column = 1);
			Quantity = Entry(justify=LEFT).grid(row = 13+i, column = 2);
			ItemTotal = Entry(justify=LEFT).grid(row = 13+i, column = 3);
			i = i+1;
		TotalButton = Button(text = "Find Total").grid(row = 13+i+1, column = 2);
		Total = Entry().grid(row = 13+i+1, column = 3);

	def ExitApplication():
		exit();

	def ResetWindow():
		StoreManagement.__init__(self);
		StoreManagement.CreateWindow(self);

	def __del__(self):
		self.myconnection.close();

def Main():
	sm = StoreManagement();
	sm.CreateWindow();

if(__name__ == "__main__"):
	Main();