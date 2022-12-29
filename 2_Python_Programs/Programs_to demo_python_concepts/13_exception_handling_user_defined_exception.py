class MyException(Exception):
	def __init__(self):
		print("User defined exception raised");
		
try:
	raise MyException();
except:
	print("Handled");