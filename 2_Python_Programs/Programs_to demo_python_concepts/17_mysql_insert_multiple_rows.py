#import mysql.connector module - to work with mysql database from python program
import mysql.connector;

#create connection using connect() method
myconnection = mysql.connector.connect(
	host = "localhost",
	user = "anwesha",
	password = "Eastonia@01",
	database = "hc_test"
)
print(myconnection);

#create cursor using cursor() method to execute queries
mycursor = myconnection.cursor();
print(mycursor);
try:
	#execute the queries using execute() method
	query = "insert into hc_test.student(name,id) values(%s, %s)";
	values = [("Utkarsh", 20),("Rahul", 30),("Rohit", 40),("Raj", 50)];
	mycursor.executemany(query,values);
	myconnection.commit();
except:
	myconnection.rollback();
	
myconnection.close();
