#This script creates the required database and tables and inserts the static data
#import the module required to work with mysql database - mysql.connector
import mysql.connector;

#create a DB connection
myconnection = mysql.connector.connect(
	host = "localhost",
	user = "anwesha",
	password = "xxxxxxx"
)	

mycursor = myconnection.cursor();

def Initialise():
	query = "create database storemanagement";
	mycursor.execute(query);
	
	query = "Create table storemanagement.Customers (CustomerId int NOT NULL AUTO_INCREMENT PRIMARY KEY, FirstName VARCHAR(50), LastName VARCHAR(50), PhoneNumber VARCHAR(25), EmailId VARCHAR(50), LastStoreVisit DATE, Address VARCHAR(50))";
	mycursor.execute(query);
	
	query = "Create table storemanagement.Items(ItemId INT NOT NULL AUTO_INCREMENT PRIMARY KEY, ItemName VARCHAR(50), UnitPrice FLOAT, Discount FLOAT)";
	mycursor.execute(query);
	
	query = "Create table storemanagement.Orders(OrderId int NOT NULL AUTO_INCREMENT PRIMARY KEY, CustomerId int, OrderDate DATE, OrderTotal FLOAT, FOREIGN KEY (CustomerId) REFERENCES Customers(CustomerId))";
	mycursor.execute(query);
	
	query = "insert into storemanagement.items (ItemName, UnitPrice, Discount) VALUES (%s, %s, %s)";
	values = [('Pen',5.00,0.0), ('Pencil',2.00,0.0), ('Note book',90.00,5.0), ('Eraser',10.00,0.0), ('Chart Paper',15.00,0.0), ('Color Pencils',5.00,0.0), ('Water Colors',5.00,10.0), ('Dictionary',150.00,15.0), ('Calendar',45.00,0.0), ('Diary',55.00,5.0)];
	mycursor.executemany(query,values);
	
	myconnection.commit();	
	
def Main():
	Initialise();

if(__name__ == "__main__"):
	Main();
	
myconnection.close();