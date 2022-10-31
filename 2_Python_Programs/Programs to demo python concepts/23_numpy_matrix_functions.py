import numpy as np;
import numpy.matlib;

def Test():
	#empty matrix - elements will have garbage value
	a1 = np.matlib.empty((3,2),dtype = int);
	print(a1);
	#matrix elements will have value 0
	a2 = np.matlib.zeros((3,3));
	print(a2);
	#matrix elements will have value 1
	a3 = np.matlib.ones((4,4));
	print(a3);
	#diagonal elements will have value 1, rest elements will have value 0
	#number of rows, number of columns, index of diagonal element
	a4 = np.matlib.eye(5,5,0);
	print(a4);
	#identity matrix
	a5 = np.matlib.identity(4);
	print(a5);
	#matrix with random elements
	a6 = np.matlib.rand(3,4);
	print(a6);
	#numpy.dot() - to calculate dot product of two matrices
	b1 = np.array([[1,2],[4,5]]);
	b2 = np.array([[2,3],[2,2]]);
	b12 = np.dot(b1,b2);
	print("b1: \n",b1);
	print("b2: \n",b2);
	print("dot product of b1 and b2: \n",np.dot(b1,b2));
	#numpy.vdot() - dot product of two vectors
	print("dot product of two vectors: \n",np.vdot(b1,b2));
	#numpy.inner() - sum of product of inner elements of one dimensional array
	c1 = np.array([1, 2, 3, 4, 5]);
	c2 = np.array([2, 2, 2, 2, 2]);
	print("c1: ",c1);
	print("c2: ",c2);
	print("numpy.inner(c1,c2): ",np.inner(c1,c2));
	#matrix multiplication
	a1 = np.array([[1, 2, 3],[1, 2, 1],[2, 2, 2]]);
	a2 = np.array([[1, 1, 1],[2, 2, 2],[3, 3, 3]]);
	print("a1: \n",a1);
	print("a2: \n",a2);
	print("Matrix multiplication: \n",np.matmul(a1,a2));
	
		
def Main():
	Test();

if(__name__ == "__main__"):
	Main();