'''
Create list from an existing list that contains unique elements from that list
'''

def Test():
	l1 = [10, 20, 30, 40, 50, 20, 30, 60, 70];
	l2 = [];
	for x in l1:
		if(x not in l2):
			l2.append(x);
	print(l1);
	print(l2);

def main():
    Test();

if __name__ == "__main__":
    main();