import numpy as np;

def Test():
	#numpy trignometric functions
	a1 = np.array([0, 30, 60, 90, 120, 150, 180, 360]);
	sinval = np.sin(a1*np.pi/180);
	cosecval = np.arcsin(sinval);
	print("Sin values: ",sinval);
	print("Cosec values: ",cosecval);
	print("Degrees: ",np.degrees(cosecval));
	cosval = np.cos(a1*np.pi/180);
	secval = np.arccos(cosval);
	print("Cos values: ",cosval);
	print("Sec values: ",secval);
	print("Degrees: ",np.degrees(secval));
	tanval = np.tan(a1*np.pi/180);
	cotval = np.arctan(tanval);
	print("Tan values: ",tanval);
	print("Cot values: ",cotval);
	print("Degrees: ",np.degrees(cotval));
	#numpy round function
	a1 = 356.789065
	print("Numpy round function: ",np.round(a1,3));
	#numpy floor function
	a1 = 356.789065
	print("Numpy round function: ",np.floor(a1));
	#numpy ceil function
	a1 = 356.789065
	print("Numpy round function: ",np.ceil(a1));
	#numpy statistical functions
	arr = np.array([[12, 34, 1, 56],[708, 90, 45, 23]]);
	print("Original array: \n",arr);
	print("Maximum element: ",np.amax(arr));
	print("Minimum element: ",np.amin(arr));
	print("Maximum element in row: ",np.amax(arr,0));
	print("Minimum element in row: ",np.amin(arr,0));
	print("Maximum element in column: ",np.amax(arr,1));
	print("Minimum element in column: ",np.amin(arr,1));
	#numpy ptp function
	print("peak to peak values along x axis: ",np.ptp(arr,0));
	print("peak to peak values along y axis: ",np.ptp(arr,1));
	#numpy percentile function
	print("Numpy percentile along x axis: ",np.percentile(arr,10,0));
	print("Numpy percentile along y axis: ",np.percentile(arr,10,1));
	#numpy median
	print("Numpy median: ",np.median(a1));
	#numpy mean
	print("Numpy mean: ",np.mean(a1));
	#numpy average
	print("Numpy average: ",np.average(a1));
	#numpy sort function
	print("Original array: \n",arr);
	print("Sorted array: \n",np.sort(arr));
	print("Sorting along the rows: \n",np.sort(arr,0));
	print("Sorting along the columns: \n",np.sort(arr,1));
	#numpy argsort
	print("Arg sort function: \n",np.argsort(arr));
	#numpy nonzero() function
	brr = np.array([12, 33, 45, 1, 3, 0, 90]);
	print("Original array: ",brr);
	print("Non zero elements: ",np.nonzero(brr));
	#numpy where function
	print("Numpy where function output: ",np.where(brr>30));
	#numpy copy and view
	crr1 = np.array([[1, 2, 3, 4, 5],[6, 7, 8, 9, 0]]);
	crr2 = np.array([[0, 0, 0, 0, 0],[0, 0, 0, 0, 0]]);
	crr1_copy = crr1.copy();
	crr2_view = crr2.view();
	print("crr1: \n",crr1);
	print("crr1_copy: \n",crr1_copy);
	print("crr2: \n",crr2);
	print("crr2_view: \n",crr2_view);
	crr1_copy.shape = 5,2;
	print("crr1: \n",crr1);
	print("crr1_copy: \n",crr1_copy);
	crr2_view.shape = 5,2;
	print("crr2: \n",crr2);
	print("crr2_view: \n",crr2_view);
	
def Main():
	Test();

if(__name__ == "__main__"):
	Main();