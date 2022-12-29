'''
1.Write a program which contains one class named as BookStore.
BookStore class contains two instance variables as Name ,Author.
That class contains one class variable as NoOfBooks which is initialise to 0.
There is one instance methods of class as Display which displays name , Author and number of
books.
Initialise instance variable in init method by accepting the values from user as name and author.
Inside init method increment value of NoOfBooks by one.
After creating the class create the two objects of BookStore class as
Obj1 = BookStore(“Linux System Programming”, “Robert Love”)
Obj1.Display() # Linux System Programming by Robert Love. No of books : 1
Obj2 = BookStore(“C Programming”, “Dennis Ritchie”)
Obj2.Display() # C Programming by Dennis Ritchie. No of books : 2
'''

class BookStore:
	NoOfBooks = 0;
	def __init__(self,name,author):
		self.Name = name;
		self.Author = author;
		BookStore.NoOfBooks = self.NoOfBooks+1;
		
	def Display(self):
		print("{} by {}. No of books : {}".format(self.Name,self.Author,BookStore.NoOfBooks));
		
def main():
	obj1 = BookStore("C Programming","Dennis Ritchie");
	obj1.Display();
	obj2 = BookStore("Linux System Programming","Robert Love");
	obj2.Display();

if __name__ == "__main__":
	main();
