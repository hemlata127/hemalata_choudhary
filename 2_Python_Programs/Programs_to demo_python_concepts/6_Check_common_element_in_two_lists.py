'''
Create list from an existing list that contains unique elements from that list
'''

def Test():
	l1 = [10, 20, 30, 40, 50, 20, 30, 60, 70];
	l2 = [34, 56, 78, 90, 40, 45];
	print("List1: ",l1);
	print("List2: ",l2);
	for x in l1:
		for y in l2:
			if y == x:
				print("Common element found: ",y);
				break;

def main():
    Test();

if __name__ == "__main__":
    main();