def Test():
	l1 = [12, 13, 14, 15, 16, 17, 18, 19, 20];
	l2 = list(map((lambda no1: no1*22),l1));
	print(l2);

def Main():
	Test();

if(__name__ == "__main__"):
	Main();