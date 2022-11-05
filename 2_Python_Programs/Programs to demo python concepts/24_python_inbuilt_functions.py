#python built-in functions
#abs() - returns absolute value of its argument
print(abs(-45));
#all() - returns True if all its arguments are True
print(all([12, 3, 4, 10]));
#any() - returns True if any of its iterable item is True
print(any([1, 0, 0, 23]));
#bin() - returns binary value of its argument
print(bin(20));
#bool() - converts to boolean
print(bool(0));
print(bool(5));
#bytes() - gives byte object
print(bytes("Hello",encoding='utf-8'));
#callable - returns True if its argument is a function (callable object)
print(callable(abs));
print(callable(list));
print(callable(__name__));
#compile() - it is used to generate compiled code from its argument which should be source code
#compiled code can then be passed to exec() function
result = compile('print("Hello world")', "test.py", 'exec');
exec(result);
#exec() - used to execute python code - it can be object code or python statement
exec('print("Jai Ganesh")');
#sum() - find sum of elements of iterable object
l1 = [1, 2, 3, 4, 5];
print(sum(l1));
#ascii() - gives a string that contains printable representation of the object
print(ascii("Hello World"));
#bytearray() - converts object to byte array
print(bytearray("Hello World", encoding = 'utf-8'));
#eval() - used to evaluate an expression
a = 10;
print(eval('a+1'));
#float() - convert an object into float
print(float(25));
#format() - used to format the string
print("{} + {} = {}".format(5, 6, 5+6));
#frozenset() - used to create a frozenset() - immutable set
s1 = frozenset((1, 2, 3, 2, 3, 4));
print("Frozenset: ",s1);
print(type(s1));
#getattr() - used to get attribute value of an object - two parameters - object and attribute name
class TestClass:
	a1 = None;
	a2 = None;
	def __init__(self, x, y):
		self.a1 = x;
		self.a2 = y;
obj = TestClass(25,50);
print(getattr(obj,'a1'));
#globals() - gives all the global identifiers
print(globals());
#hasattr() - checks if the object has specified attribute
print(hasattr(obj,'a2'));
print(hasattr(obj,'s2'));
#iter() - used to create an iterable object - use next() to move through the iterable object
iterobj = iter(l1);
print(type(iterobj));
print(next(iterobj));
print(next(iterobj));
#len() - returns the length of the sequence
print(len("Hello World"));
print(len([1, 2, 3, 4, 5, 6 ,7, 9]));
print(len({1, 2, 3, 4, 2, 3, 4, 5, 6,7}));
#list() - used to create a list
print(list("HELLO"));
#locals() - gives the list of local identifiers
def Test1():
	x1 = 55;
	x2 = 88;
	return locals();
print(Test1());
#map() - takes two arguments - argument1 = function, argument2 = iterable, applies function on each item of iterable
def Test2(no1):
	return no1**2;
l1 = [1, 2, 3, 4, 5, 6];
result = map(Test2,l1);
print(list(result));
#memoryview() - gives memory view of an object
print(memoryview(bytearray('ABC',encoding='utf-8'))[0]);
#object() - used to create an empty object
obj = object();
print(type(obj));
print(type(object()));
#open() - opens a file in specified mode
fileptr = open("test1.txt",'r+');
if(fileptr):
	print("File opened");
#close() - close the opened file
fileptr.close();
print("File closed");
#chr() - gives string representation of the unicode character
print(chr(65));
print(chr(650));
#complex() - used to create complex number, first parameter is real part, second parameter is imaginary part
print(complex(1,2));
#delattr() - used to delete the attribute of a class
class TestClass:
	s1 = None;
	s2 = None;
	def Test1():
		pass;
obj = TestClass();
print(dir(obj));
delattr(TestClass,'s1');
obj = TestClass();
print(dir(obj));
#dir() - used to list all the symbols in the current scope
print(dir());
#divmod() - finds quotient and remainder of two numbers
print(divmod(25,6));
#enumerate() - iterates through the sequence and fetches the index and value at the index
l1 = [11, 22, 33, 44, 55, 66];
s1 = "HELLO";
print(list(enumerate(l1)));
print(list(enumerate(s1)));
#dict() - used to create a dictionary - arguments are passed as name value format
d1= dict(A=11,B=22,C=33);
print(d1);
#filter() - takes 2 arguments, 1 - function that returns boolean value, 2 - iterable
#output is all those elements from the iterable for which the function returns True
l1 = [11, 12, 13, 14, 15, 16, 17];
def Even(no):
	return (no%2 == 0);
result = filter(Even,l1);
print(list(result));
print(list(filter((lambda no: no%2==0),l1)));
#hash() - gives the hash value of its argument
print(hash(125.5));
#help() - displays the help documenation of a function, module, class
print(help("keywords")); #displays all the keywords
print(help(dir)); #help about dir function
#min() - gives minimum of its iterable argument
print(min(l1));
#max() - gives maximum of its iterable argument
print(max(l1));
#set() - used to create a set
s1 = set((12,2,3,4,1,2,3));
print(s1);
#hex() - used to find a hex value
print(hex(20));
#id() - gives identifier of the object
print(id(l1));
#setattr() - sets value of an attribute
class TestClass:
	s1 = None;
obj = TestClass();
print(obj.s1);
setattr(obj,'s1',10);
print(obj.s1);
#slice() - creates slice object - slice object is used to create slice of the sequence
str1 = "Hello World";
s1 = slice(5); #creates slice object - 0 to 5
print(str1[s1]); #OP = Hello
s1 = slice(0,10,2); # creates slice object - 0 to 10 at step of 2
print(str1[s1]); #HloWr
#sorted() - used to sort the elements of the iterable object
s1 = "Hello World";
print(sorted(s1));
#next() - fetch the next item from the collection
l1 = iter([12, 13, 14, 15]);
print(next(l1));
print(next(l1));
#input() - read the input from the user
num = input("Enter number: ");
print("Entered number is: ",int(num));
#int() - used to convert to int
ch = 4.5;
print(int(ch));
#isinstance() - used to check if the object is instance of the class
print(isinstance(obj,TestClass));
#oct() - used to convert to octal
print(oct(15));
#ord() - used to display the ascii value of the character
print(ord('A'));
#pow() - used to find the exponent value
print(pow(5,3));
#print() - to print the string on the console
print("{} + {} is {}".format(5,6,5+6));
#range() - to create a sequence of numbers in specified range
for x in range(10):
	print(x,end = " ");
print();
#reversed()
print(list(reversed("Hello")));
#round() - rounds up the value
print(round(5.67));
#issubclass() - checks if class is subclass of given class
class Parent:
	pass;
class Child(Parent):
	pass
print(issubclass(Child,Parent));
#str() - convert to string
print(str(123));
#tuple() - creates a tuple
t1 = tuple((1,2,2,3,4,1));
print(t1);
#type() - prints the type of the argument
print(type(t1));
#vars() - prints list of all the variables of the class
print(vars(TestClass));
def TestFunction():
	a = None;
	b = 12;
	c = 4.5;
	d = "Hello";
	print(locals());
TestFunction();
#zip() - combine elements of multiple sequence at same index
l1 = [1, 2, 3, 4, 5, 6];
s1 = (1, 2, 6, 8, 7);
print(list(zip(l1,s1)));
