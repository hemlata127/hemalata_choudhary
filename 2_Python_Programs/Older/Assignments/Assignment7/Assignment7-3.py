'''
3. Write a program which contains one class named as Numbers.
Arithmetic class contains one instance variables as Value.
Inside init method initialise that instance variables to the value which is accepted from user.
There are four instance methods inside class as ChkPrime(), ChkPerfect(), SumFactors(),
Factors().
ChkPrime() method will returns true if number is prime otherwise return false.
ChkPerfect() method will returns true if number is perfect otherwise return false.
Factors() method will display all factors of instance variable.
SumFactors() method will return addition of all factors. Use this method in any another method
as a helper method if required.
After designing the above class call all instance methods by creating multiple objects.
'''

class Numbers:

	def __init__(self,Value):
		self.Value = Value;
	
	def ChkPrime(self):
		if self.Value == 1:
			return False;
		elif self.Value == 2:
			return True;
		else:
			for i in range(2,self.Value):
				if (self.Value)%i==0:
					return False;
			return True;
	
	def ChkPerfect(self):
		sum = 0;
		for i in range(1,self.Value):
			if (self.Value)%i == 0:
				sum = sum+i;
		if sum == self.Value:
			return True;
		else:
			return False;
	
	def Factors(self):
		factors = []
		for i in range(1,self.Value+1):
			if self.Value%i==0:
				factors.append(i);
		return factors;
				
	
	def SumFactors(self):
		ans = 0;
		for i in range(1,(self.Value)+1):
			if (self.Value)%i==0:
				ans = ans + i;
		return ans;


def main():
	obj1 = Numbers(50);
	print("{} is prime number: {}".format(obj1.Value,obj1.ChkPrime()));
	print("{} is perfect: {}".format(obj1.Value,obj1.ChkPerfect()));
	print("Factors of {} are {}".format(obj1.Value,obj1.Factors()));
	print("Sum of factors of {} is {}".format(obj1.Value,obj1.SumFactors()));
	
if __name__ == "__main__":
	main();