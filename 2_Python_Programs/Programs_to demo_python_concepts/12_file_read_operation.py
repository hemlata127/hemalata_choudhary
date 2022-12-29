def Test():
	fptr = open("Test.txt",'r');
	if(fptr):
		print("File opened successfully");
	content = fptr.read();
	print(content);
	fptr.close();
	
def Main():
	Test();

if(__name__ == "__main__"):
	Main();