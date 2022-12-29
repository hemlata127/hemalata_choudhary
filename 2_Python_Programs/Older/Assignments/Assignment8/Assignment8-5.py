'''
5.Design python application which contains two threads named as thread1 and thread2.
Thread1 display 1 to 50 on screen and thread2 display 50 to 1 in reverse order on
screen. After execution of thread1 gets completed then schedule thread2.
'''
import threading;
def fun1(lock):
	lock.acquire();
	for i in range(1,51):
		print("Thread1, value:",i);
	lock.release();

def fun2(lock):
	lock.acquire();
	for i in range(50,0,-1):
		print("Thread2, value:",i);
	lock.release();
		
def main():
	lock = threading.Lock();
	t1 = threading.Thread(target=fun1,args=(lock,));
	t2 = threading.Thread(target=fun2,args=(lock,));
	t1.start();
	t2.start();
	
	t1.join();
	t2.join();

if __name__ == "__main__":
	main();