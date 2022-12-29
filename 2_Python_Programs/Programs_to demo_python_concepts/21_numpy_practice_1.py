import numpy as np;

def Test():
	l1 = [1, 2, 3, 4, 5];
	arr = np.array(l1);
	print(arr);
	brr = np.array(l1, complex);
	print(brr);
	print("Dimension of the array: ",arr.ndim);
	print("Item size: ",arr.itemsize);
	print("Array shape: ",arr.shape);
	print("Array size: ",arr.size);
	l2 = [[1, 2], [3, 4], [5, 6]];
	crr = np.array(l2);
	print("Original array: \n",crr);
	print("Reshaped array: \n",crr.reshape(2, 3));
	print("Element crr[0,1]: ",crr[0,1]);
	#gives 10 evenly spaced values between 5 and 25
	print(np.linspace(5,25,10));
	#finding max, min and sum of array elements
	a1 = np.array([10, 20, 5, 30, 40, 2, 80]);
	print("Original array: ",a1);
	print("Sum of array elements: ",a1.sum());
	print("Maximum element: ",a1.max());
	print("Minimum element: ",a1.min());
	#x axis is represented by 0 and y axis is represented by 1
	a2 = np.array([[1, 2, 3, 4],[5, 6, 2, 3]]);
	print("Original array a2: \n",a2);
	print("Max in each row: \n",a2.max(axis = 0));
	print("Min in each row: \n",a2.min(axis = 0));
	print("Sum of row elements: \n",a2.sum(axis = 0));
	print("Max in each column: \n",a2.max(axis = 1));
	print("Min in each column: \n",a2.min(axis = 1));
	print("Sum of each column elements: ",a2.sum(axis = 1));
	#squareroot of each array element
	print("Square root of each array element: \n", np.sqrt(a2));
	#standard deviation of each array element
	print("Standard deviation of each array element: \n", np.std(a2));
	#Arithmetic operations on two arrays - addition, multiplication, division
	b1 = np.array([[10, 20, 30],[40, 50, 60]]);
	b2 = np.array([[5, 10, 15],[20, 25, 30]]);
	print("b1: \n",b1);
	print("b2: \n",b2);
	print("b1+b2: \n",b1+b2);
	print("b1*b2: \n",b1*b2);
	print("b1/b2: \n",b1/b2);
	print("b1-b2: \n",b1-b2);
	#concatenation of the array
	print("Horizontal concatenation of b1 and b2: \n",np.hstack((b1,b2)));
	print("Vertical concatenation of b1 and b2: \n",np.vstack((b1,b2)));
	#creating numpy array - empty array of given shape and data type
	print("Empty array: ");
	b3 = np.empty((3,2),dtype=int);
	print(b3);
	#initialise each array element by 0
	print("Zero array: \n",np.zeros((3,2),dtype=int, order = 'C'));
	print("Zero array: \n",np.zeros((3,2),dtype=int, order = 'F'));
	#initialise each element as 1
	print("Array with each element initialised as 1: \n",np.ones((3,2),dtype=int, order = 'C'));
	#converting existing python sequence into numpy array
	l3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
	t1 = (11, 22, 33, 44, 55, 66, 77, 88, 99);
	print("np.asarray(l3): \n",np.asarray(l3));
	print("np.asarray(t1): \n",np.asarray(t1));
	print("type of np.asarray(t1): \n",type(np.asarray(t1)));
	#creating numpy array from buffer
	s1 = b'hello world';
	print("numpy array from buffer: \n",np.frombuffer(s1,dtype='S1'));
	print("type(s1): ",type(s1));
	print("type(np.frombuffer(s1,dtype='S1')): ",type(np.frombuffer(s1,dtype='S1')));
	#numpy array from iterable object
	l1 = [11, 22,33, 44, 55];
	print("Numpy array from iterable object: ",np.fromiter(iter(l1), dtype=int));
	#numpy array from range
	print("Numpy array from specified range: \n",np.arange(1,50,3,dtype=int));
	#numpy linspace - similar to arange(), but does not allow us to specify the step
	#returns evenly spaced elements in the specified interval
	print("Numpy array using linspace(): \n",np.linspace(2, 20, 10, dtype=complex));
	#numpy array using numbers on log scale
	print("Numpy array using numbers on logscale: \n",np.logspace(1, 20, num = 10, dtype = float));
	#example of array broadcasting - mathematical operations between arrays of different shapes
	#smaller arrays are broadcasted to larger arrays to make the shapes compatible
	c1 = np.array([[1, 2, 3, 4], [2, 0, 2, 0]]);
	c2 = np.array([5, 6, 7, 8]);
	print("Array c1: \n",c1);
	print("Array c2: \n",c2);
	print("c1+c2: \n",c1+c2);
	#numpy array iterator
	d1 = np.array([[1,2, 3, 4],[5, 6, 7, 8]]);
	print("Original array: \n",d1);
	print("Iterate through the array: ");
	for x in np.nditer(d1):
		print(x, end=', ');
	print("\nTranspose of array: \n",d1.T);
	print("Iterate through the transposed array: ");
	for x in np.nditer(d1.T):
		print(x, end=', ');
	print();
	#numpy bit wise and operator
	a1 = 10;
	a2 = 12;
	print("binary 10: ",bin(a1));
	print("binary 12: ",bin(a2));
	print("bitwise 10 and 12: ",bin(np.bitwise_and(a1,a2)));
	#numpy bit wise or operator
	a1 = 10;
	a2 = 12;
	print("binary 10: ",bin(a1));
	print("binary 12: ",bin(a2));
	print("bitwise 10 and 12: ",bin(np.bitwise_or(a1,a2)));
	#numpy bitwise_invert operator
	a1 = np.array([10], dtype=np.uint8);
	print("binary 10: ",np.binary_repr(10,8));
	print("invert of 10: ",np.invert(a1));
	result = np.invert(a1);
	print("binary of invert of 10: ",np.binary_repr(result[0],8));
	#numpy right shift operator
	a1 = np.array([45]);
	print("Binary 45: ",np.binary_repr(45,8));
	result = np.right_shift(45,2);
	print("Binray right shift 45 by 2 digits:",np.binary_repr(result,8));
	#numpy left shift operator
	a1 = np.array([45]);
	print("Binary 45: ",np.binary_repr(45,8));
	result = np.left_shift(45,2);
	print("Binray left shift 45 by 2 digits:",np.binary_repr(result,8));
	#numpy string functions
	a1 = np.array(['A', 'B', 'C', 'D']);
	a2 = np.array(['a', 'b', 'c', 'd']);
	print("Numpy add: ", np.char.add(a1,a2));
	#numpy multiply
	a1 = np.array(['A']);
	print("Numpy multiply: ",np.char.multiply(a1,3));
	#numpy center align
	a1 = np.array(['Hello World']);
	print("Numpy center align: \n",np.char.center(a1[0], 50, '*'));
	#numpy capitalize
	a1 = np.array(['hello world']);
	print("Numpy capitalize: \n",np.char.capitalize(a1));
	#numpy title
	a1 = np.array(['unix operating system']);
	print("Numpy title: \n",np.char.title(a1));
	#numpy lower
	a1 = np.array([['Unix'],['Operating'],['System']]);
	print("Numpy lower: \n",np.char.lower(a1));
	#numpy upper
	a1 = np.array([['Unix'],['Operating'],['System']]);
	print("Numpy upper: \n",np.char.upper(a1));
	#numpy split
	print("Numpy split: \n",np.char.split("unix operating system by Maurice J Bach", sep = " "));
	#numpy splitlines
	s1 = """Hello world
	Please get this book
	Unix Operating System by Maurice J Bach""";
	s1 = np.array(s1);
	print("Numpy splitlines: \n",np.char.splitlines(s1));
	#numpy strip
	print("Numpy strip: \n",np.char.strip("       Hello World          "));
	#numpy join
	s1 = "unix";
	print("Numpy join: ",np.char.join(' ',s1));
	#numpy replace
	s1 = "Unix Operating System";
	print("Original string: ",s1);
	print("String after using numpy replace: ",np.char.replace(s1,'Unix','Windows'));
	#numpy encode and decode
	s1 = "Unix operating system";
	result = np.char.encode(s1,'cp500');
	print("Original string: ",s1);
	print("Encoded string: ",result);
	print("Decoded string: ",np.char.decode(result,'cp500'));

def Main():
	Test();

if(__name__ == "__main__"):
	Main();