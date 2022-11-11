#import library required for DB connection
import mysql.connector
#import library required to get current date
from datetime import datetime

#create a DB connection
mydb = mysql.connector.connect(
	host = "localhost",
	user = "anwesha",
	password = "xxxxxx"
)	

mycursor = mydb.cursor();

#display the story banner
def DisplayBanner():
	print("========================================");
	print("WELCOME TO VENUS STORE!!");
	print("========================================\n");

#show menu with options supported by the application
def DisplayMenu():
	while(True):
		print("What action do you want to perform?");
		print("1. Process new order");
		print("2. Search last customer order");
		print("3. Display customer details");
		print("0. Exit application");
		choice = int(input("Please select an option: "));
		if(choice == 1):
			ProcessOrder();
		elif(choice == 2):
			SearchOrder();
		elif(choice == 3):
			ShowCustomerDetails();
		elif(choice == 0):
			print("Thank you for using the application!!!");
			break;
		else:
			print("Wrong choice, please try again");

#process a new order for the customer
#check if customer already exists, if it exists display a welcome message 
#else accept customer details and store them in db and then proceed with order processing
def ProcessOrder():
	phone = int(input("Please enter your phone number: "));
	sql_select_query = """select * from storemanagement.customers where phonenumber = %s"""
	mycursor.execute(sql_select_query, (phone,))
	myresult = mycursor.fetchall();
	if len(myresult) == 0:
		customerid = AcceptNewCustomerDetails(phone);
		GenerateNewOrder(customerid);
	else:
		print("========================================\n");
		print("Welcome ",list(myresult)[0][1], list(myresult)[0][2]);
		customerid = list(myresult)[0][0];
		GenerateNewOrder(customerid);
	
#accept customer details for a new customer who visited the store for first time
#store customer details in db
def AcceptNewCustomerDetails(customer_phone):
	print("You have entered our store for the first time");
	print("Please provide us some details to help us serve you better!");
	first_name = input("First Name: ");
	last_name = input("Last Name: ");
	email_id = input("EmailId: ");
	now = datetime.now();
	formatted_date = now.strftime('%Y-%m-%d %H:%M:%S');
	customer_address = input("Address: ");
	sql_insert_query = """INSERT INTO storemanagement.customers (FirstName, LastName, PhoneNumber, EmailId, LastStoreVisit, Address) VALUES (%s, %s, %s, %s, %s, %s)""";
	val = (first_name, last_name, customer_phone, email_id, formatted_date, customer_address);
	mycursor.execute(sql_insert_query, val);
	mydb.commit();
	sql_select_query = """select customerid from storemanagement.customers where phonenumber = %s"""
	mycursor.execute(sql_select_query, (customer_phone,));
	myresult = mycursor.fetchall();
	customerid = list(myresult)[0][0];
	return customerid;

#add items to the cart, process order and display order total
#store order details in db
def GenerateNewOrder(customerid):
	order_total = 0;
	ans = 0;
	quantity = 0;
	print("Let's add items to your cart");
	mycursor.execute("select * from storemanagement.items");
	result = mycursor.fetchall();
	for i in result:
		ans = int(input("Add "+i[1]+"?"+" [1] Yes, [0] No: "));
		if(ans == 1):
			quantity = int(input("Enter quantity: "));
			discount = i[3]/100;
			discounted_price = i[2] - discount;
			order_total = order_total + (discounted_price * quantity);
			print(order_total);
	now = datetime.now();
	formatted_date = now.strftime('%Y-%m-%d %H:%M:%S');
	sql_insert_query = """INSERT INTO storemanagement.orders (CustomerId, OrderDate, OrderTotal) VALUES (%s, %s, %s)""";
	val = (customerid, formatted_date, order_total);
	mycursor.execute(sql_insert_query, val);
	mydb.commit();
	print("Thank you for placing an order.")
	print("Your order total is: "+str(order_total)+"\n");
	print("========================================\n");

#search last order for the customer
def SearchOrder():
	phone = int(input("Please enter your phone number: "));
	sql_select_query = """select * from storemanagement.customers where phonenumber = %s"""
	mycursor.execute(sql_select_query, (phone,));
	myresult = mycursor.fetchall();
	if(len(myresult) == 0):
		print("No orderdetails found for customer with this phone number");
	else:
		print("Welcome ",list(myresult)[0][1], list(myresult)[0][2]);
		customerid = list(myresult)[0][0];
		sql_select_query = """select * from storemanagement.orders where customerid = %s order by orderdate desc"""
		mycursor.execute(sql_select_query, (customerid,))
		myresult = mycursor.fetchall();
		print("Here are your last order details: ");
		print("Last Order Date: ",list(myresult)[0][2]);
		print("Last Order Total ",list(myresult)[0][3]);
	print("========================================\n");

#show customer details of a customer with given phone number
#if no customer details found for given phone number, display proper message
def ShowCustomerDetails():
	phone = int(input("Please enter your phone number: "));
	sql_select_customer_query = """select * from storemanagement.customers where phonenumber = %s"""
	mycursor.execute(sql_select_customer_query, (phone,))
	myresult = mycursor.fetchall();
	if len(myresult) == 0:
		print("No details found for customer with this phone number");
	else:
		print("========================================\n");
		print("CUSTOMER DETAILS:")
		print("Customer Name: "+myresult[0][1]+" "+myresult[0][2]);
		print("Phone number: "+myresult[0][3]);
		print("EmailId: "+myresult[0][4]);
		print("Last Store Visit Date: "+str(myresult[0][5]));
		print("Address: "+myresult[0][6]);
		print("========================================\n");

#entry point function
def main():
	DisplayBanner();
	DisplayMenu();	

if __name__ == "__main__":
    main();

#close the db connections
mycursor.close();
mydb.close();
