'''
1.Design automation script which display information of running processes as its name, PID,
Username.
Usage : ProcInfo.py
'''
import sys;
import psutil;

def ProcInfo():
	l1 = [];
	for i in psutil.process_iter():
		l1.append(i.as_dict(attrs=['name','pid','username']));
	
	for i in l1:
		print(i);



def main():
	print("Automation script by Hemalata Choudhary");
	print("Application name: ",sys.argv[0]);
	
	if len(sys.argv)==2 and sys.argv[1] == '-h':
		print("Script to display process information");
		
	if len(sys.argv)==2 and sys.argv[1] == '-u':
		print("python ScriptName");
	
	ProcInfo();


if __name__ == "__main__":
	main();
