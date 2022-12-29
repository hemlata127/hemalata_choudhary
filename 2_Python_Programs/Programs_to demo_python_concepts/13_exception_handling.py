import os;

def Test():
	l1 = [10, 20, 30, 40];
	try:
		for i in range(5):
			print("Index = {}, element = {}".format(i,l1[i]));
	except:
		print("Index out of range");
	print("After try catch blocks");
	raise Exception("Explicitly raised exception");
	
def Main():
	Test();

if(__name__ == "__main__"):
	Main();