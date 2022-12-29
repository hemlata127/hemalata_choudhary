'''
1.Design python application which creates two thread named as even and odd. Even
thread will display first 10 even numbers and odd thread will display first 10 odd
numbers.
'''
import threading;

def even():
	for i in range(1,21):
		if i%2==0:
			print("Even",i);

def odd():
	for i in range(1,21):
		if not i%2==0:
			print("Odd",i);

def main():

	thread1 = threading.Thread(target = even);
	thread2 = threading.Thread(target = odd);
	
	thread1.start();
	thread2.start();
	
	thread1.join();
	thread2.join();

if __name__ == main():
	main();