import mysql.connector;

myconnection = mysql.connector.connect(
    host = "localhost",
    username = "anwesha",
    password = "Eastonia@01"
);

mycursor = myconnection.cursor();

query = "create database telephonedirectory";
mycursor.execute(query);

create_table_query = "create table telephonedirectory.contacts(ContactId int NOT NULL AUTO_INCREMENT PRIMARY KEY, FirstName VARCHAR(50), LastName VARCHAR(50), PhoneNumber VARCHAR(25), EmailId VARCHAR(50), Address VARCHAR(50))";
mycursor.execute(create_table_query);

myconnection.close();
