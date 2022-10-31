'''
Using tuple data type in python
'''

def Test():
	t1 = (12,13, 20, 30, 40);
	print(t1);
	print(type(t1));
	print(t1[3]);
	for x in range(0,len(t1)):
		print(t1[x],end=' ');
		
	print("Demo of slicing: ");
	print(t1[1:3]);

def main():
    Test();

if __name__ == "__main__":
    main();'''
Using tuple data type in python
'''

def Test():
	t1 = (12,13, 20, 30, 40, 12, 50, 12);
	print(t1);
	print(type(t1));
	print(t1[3]);
	print("Iterating through tuple: ");
	for x in range(0,len(t1)):
		print(t1[x],end=' ');
		
	print("Demo of slicing: ");
	print(t1[1:3]);
	print("Repeating tuple: ");
	print(t1*2);
	print("Count occurance of tuple element - 12: ");
	print(t1.count(12));
	print("Get index of tuple element - 12: ");
	print(t1.index(12));
	print("Check if element is member of tuple: - 11");
	print(11 in t1);
	print("Deleting a tuple - t1: ");
	del t1;
	

def main():
    Test();

if __name__ == "__main__":
    main();