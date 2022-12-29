'''
3. Write a program which contains one class named as Arithmetic.
Arithmetic class contains three instance variables as Value1 ,Value2.
Inside init method initialise all instance variables to 0.
There are three instance methods inside class as Accept(), Addition(), Subtraction(),
Multiplication(), Division().
Accept method will accept value of Value1 and Value2 from user.
Addition() method will perform addition of Value1 ,Value2 and return result.
Subtraction() method will perform subtraction of Value1 ,Value2 and return result.
Multiplication() method will perform multiplication of Value1 ,Value2 and return result.
Division() method will perform division of Value1 ,Value2 and return result.
After designing the above class call all instance methods by creating multiple objects.
'''
class Arithmetic:
	def __init__(self):
		self.Value1 = 0;
		self.Value2 = 0;
		
	def Accept(self):
		self.Value1 = int(input("Enter Value1: "));
		self.Value2 = int(input("Enter Value2: "));
	
	def Addition(self):
		return self.Value1+self.Value2;
	
	def Subtraction(self):
		return self.Value1-self.Value2;
	
	def Multiplication(self):
		return self.Value1*self.Value2;
	
	def Division(self):
		return self.Value1/self.Value2;
	
def main():
	obj1 = Arithmetic();
	obj1.Accept();
	print("Sum of two {} and {} is {}".format(obj1.Value1,obj1.Value2,obj1.Addition()));
	print("Difference of two {} and {} is {}".format(obj1.Value1,obj1.Value2,obj1.Subtraction()));
	print("Multiplication of two {} and {} is {}".format(obj1.Value1,obj1.Value2,obj1.Multiplication()));
	print("Quotient of two {} and {} is {}".format(obj1.Value1,obj1.Value2,obj1.Division()));

if __name__ == "__main__":
	main();