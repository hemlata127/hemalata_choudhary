#import mysql.connector module - to work with mysql database from python program
import mysql.connector;

#create connection using connect() method
myconnection = mysql.connector.connect(
	host = "localhost",
	user = "anwesha",
	password = "Eastonia@01"
)
print(myconnection);

#create cursor using cursor() method to execute queries
mycursor = myconnection.cursor();
print(mycursor);
try:
	#execute the queries using execute() method
	mycursor.execute("create database hc_test");
	dbs = mycursor.execute("show databases");
	for x in mycursor:
		print(x);
	mycursor.execute("drop database hc_test");
	dbs = mycursor.execute("show databases");
	for x in mycursor:
		print(x);
except:
	myconnection.rollback();
	
myconnection.close();
