'''
2.Design python application which creates two threads as evenfactor and oddfactor.
Both the thread accept one parameter as integer. Evenfactor thread will display
addition of even factors of given number and oddfactor will display addition of odd
factors of given number. After execution of both the thread gets completed main
thread should display message as “exit from main”.
'''
import threading;
def evenfactor(num1):
	evensum = 0;
	for i in range(1,num1):
		if (num1%i==0) and (i%2==0):
			print("Evenfactor:",i);
			evensum = evensum+i;
	print("Evensum is",evensum);

def oddfactor(num2):
	oddsum = 0;
	for i in range(1,num2):
		if (num2%i ==0) and (i%2 != 0):
			print("Oddfactor:",i);
			oddsum = oddsum+i;
	print("Oddsum is",oddsum);
			

def main():
	num = int(input("Enter a number: "));
	t1 = threading.Thread(target = evenfactor,args = (num,));
	t2 = threading.Thread(target = oddfactor,args = (num,));
	
	t1.start();
	t2.start();
	
	t1.join();
	t2.join();

if __name__ == "__main__":
	main();
