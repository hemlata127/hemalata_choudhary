'''
3.Design python application which creates two threads as evenlist and oddlist. Both the
threads accept list of integers as parameter. Evenlist thread add all even elements
from input list and display the addition. Oddlist thread add all odd elements from input
list and display the addition.
'''
import threading;
def evenlist(l1):
	sum = 0;
	for i in l1:
		if i%2==0:
			sum = sum+i;
	print("Evensum:",sum);

def oddlist(l1):
	sum = 0;
	for i in l1:
		if i%2 !=0:
			sum = sum+i;
	print("Oddsum",sum);

def main():
	l1 = [12,3,14,56,78,1,4,5,7,23,90,11,15];
	
	t1 = threading.Thread(target=evenlist,args=(l1,));
	t2 = threading.Thread(target=oddlist,args=(l1,));
	
	t1.start();
	t2.start();
	
	t1.join();
	t2.join();

if __name__ == "__main__":
	main();