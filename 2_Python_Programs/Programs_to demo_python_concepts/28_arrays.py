#array module to create the array and use array functions
import array;

def Test():
	#array() method from array module to create an array
	arr = array.array('i',[10, 20, 30, 40, 50]);
	print(arr);
	for x in arr:
		print(x,end=' ');
	print();
	#changing elements of array
	arr[0:2] = array.array('i',[11,22,33]);
	print(arr);
	del arr[0];
	print(arr);
	print("Length of array: ",len(arr));
	brr = array.array('i',[100,200,300,400]);
	print("Concatenated arrays: ",arr+brr);
	print("Last element of brr: ",brr[-1]);
	
def Main():
	Test();

if(__name__ == "__main__"):
	Main();