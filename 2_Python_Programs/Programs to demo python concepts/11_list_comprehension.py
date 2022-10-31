def Test():
	l1 = [12, 13, 14, 15, 16, 17, 18, 19, 20];
	l2 = []
	for x in l1:
		if(x%2 == 0):
			l2.append(x);
	print(l2);
	#creating a list using list comprehension
	l3 = [x for x in l1 if x%2 == 0];
	print(l3);
	l4 = [x for x in range(10)];
	print(l4);
	l5 = [x for x in range(0,20,2)];
	print(l5);
	l6 = ['apple', 'banana', 'orange', 'kiwi'];
	print(l6);
	l7 = [x.upper() for x in l6];
	print(l7);

def Main():
	Test();

if(__name__ == "__main__"):
	Main();