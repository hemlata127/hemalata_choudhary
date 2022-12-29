'''
4.Design python application which creates three threads as small, capital, digits. All the
threads accepts string as parameter. Small thread display number of small characters,
capital thread display number of capital characters and digits thread display number of
digits. Display id and name of each thread.
'''
import threading;
import os;
def small(s1):
	print("Id of thread1 is:",threading.current_thread());
	count = 0;
	for i in s1:
		if i.islower() == True:
			count = count+1;
	print("Number of small characters:",count);

def capital(s1):
	print("Id of thread2 is:",threading.current_thread());
	count = 0;
	for i in s1:
		if i.isupper() == True:
			count = count+1;
	print("Number of capital characters:",count);
	
def digits(s1):
	print("Id of thread3 is:",threading.current_thread());
	count = 0;
	for i in s1:
		if i.isdigit() == True:
			count = count+1;
	print("Number of digits:",count);

def main():
	name = input("Enter a string: ");
	s1 = list(name);
	
	t1 = threading.Thread(target=small,args=(s1,));
	t2 = threading.Thread(target=capital,args=(s1,));
	t3 = threading.Thread(target=digits,args=(s1,));
	
	t1.start();
	t2.start();
	t3.start();
	
	t1.join();
	t2.join();
	t3.join();
	
if __name__ == "__main__":
	main();
