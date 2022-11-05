def Sum(no1, no2):
	return (no1+no2);

def Outer(fun):
	def Inner():
		result = Sum(num1,num2);
		return result;
	return Inner();
	
Sum = Outer(Sum);
	
def Main():
	no1 = 10;
	no2 = 20;
	ans = Sum(no1,no2);
	print("Answer = ",ans);
	
if(__name__ == "__main__"):
	Main();
	