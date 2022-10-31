'''
Using set data type in python
'''

def Test():
	s1 = {10, 20, 20, 30, 40, 50, 60, 10,(100,200)};
	print(type(s1));
	print(s1);
	#Iterating through the tuple elements
	for x in s1:
		print(x,end=' ');
		
	print();
		
	#this creates a dictionary
	s2 = {};
	print(type(s2));
	#this created empty set
	s3 = set();
	print(type(s3));
	#add single element to tuple
	s1.add(500);
	print(s1);
	#add multiple elements to tuple
	s1.update([11,22,33]);
	print(s1);
	#remove an element - throws error if element does not exist
	s1.remove(11);
	print(s1);
	#remove element - if element is not present - no error
	s1.discard(501);
	print(s1);	
	#remove last item
	s1.pop();
	print(s1);
	s2 = {10, 20, 30, 40};
	s3 = {30, 40, 50};
	#set union
	print(s2.union(s3));
	#set intersection
	print(s2.intersection(s3));
	
	
def main():
    Test();

if __name__ == "__main__":
    main();