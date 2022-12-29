import threading;
import time;

def FindSquare(l1):
	for x in l1:
		print("Square of {} = {}".format(x, x*x));
		
def FindCube(l1):
	for x in l1:
		print("Cube of {} is {}".format(x, x*x*x));
		
l1 = [2, 3, 4, 5, 6, 7, 8];		

t1 = threading.Thread(target=FindSquare,args=(l1,));
t2 = threading.Thread(target=FindCube,args=(l1,));

time1 = time.time();

t1.start();
t2.start();

t1.join();
t2.join();

print("Time takes for execution: ",time.time()-time1);
print("Resume main thread");
print("Completed");