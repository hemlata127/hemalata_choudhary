'''
3. Design automation script which accept directory name from user and create log file in that
directory which contains information of running processes as its name, PID, Username.
Usage : ProcInfoLog.py Demo
'''
import sys;
import psutil;
import os;

def ProcInfo(dirname):
	l1 = [];
	for i in psutil.process_iter():
		l1.append(i.as_dict(attrs=['name','pid','username']));
		
	if os.path.isdir(dirname) == False:
		os.mkdir(dirname,mode=777);
		
	if os.path.isabs(dirname) == False:
		dirname = os.path.abspath(dirname);
	
	filename = dirname+"/log.txt";
	fd1 = open(filename,'w');
	
	fd1.write("Process information");
	
	for i in l1:
		fd1.write("\n"+"-"*60);
		fd1.write("\n"+str(i));
	
	fd1.close();


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