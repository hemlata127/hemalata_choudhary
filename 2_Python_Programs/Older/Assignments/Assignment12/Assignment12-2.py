'''
2.Design automation script which accept process name and display information of that process if
it is running.
Usage : ProcInfo.py Notepad
'''
import sys;
import psutil;

def ProcInfo(procname):
	l1 = [];
	for i in psutil.process_iter():
		l1.append(i.as_dict(attrs=['name','pid','username']));
	
	for i in l1:
		if procname in i.values():
			print(i);



def main():
	print("Automation script by Hemalata Choudhary");
	print("Application name: ",sys.argv[0]);
	if len(sys.argv)!=2:
		print("Invalid number of arguments. Use -h or -u options for help or usage");
	
	if sys.argv[1] == '-h':
		print("Script to display process information");
		
	if sys.argv[1] == '-u':
		print("python ScriptName");
	
	ProcInfo(sys.argv[1]);


if __name__ == "__main__":
	main();