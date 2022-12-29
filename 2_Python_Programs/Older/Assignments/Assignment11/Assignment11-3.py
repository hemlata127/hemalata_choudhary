'''
3. Design automation script which accept directory name and delete all duplicate files from that
directory. Write names of duplicate files from that directory into log file named as Log.txt.
Log.txt file should be created into current directory.
Usage : DirectoryDusplicateRemoval.py “Demo”
Demo is name of directory.
'''
import sys;
import os;
import hashlib;

def GetCheckSum(name,blocksize=1024):
	fd = open(name,'rb');
	hasher = hashlib.md5();
	buf = fd.read(blocksize);
	
	while len(buf)>0:
		hasher.update(buf);
		buf = fd.read(blocksize);
	fd.close();
	return hasher.hexdigest();

def DuplicateFiles(path):
	if os.path.isdir(path) == False:
		print(path+" is not a directory");
		return;
	if os.path.isabs(path) == False:
		path = os.path.abspath(path);
		
	d1 = {};
		
	for Folder,Subfolder,Files in os.walk(path):
		for name in Files:
			name = os.path.join(Folder,name);
			checksum = GetCheckSum(name);
			if checksum in d1:
				d1[checksum].append(name);
			else:
				d1[checksum] = [name];
	
	l1 = list(filter(lambda x:len(x)>1,d1.values()));
			
	fd1 = open("log.txt",'w');
	fd1.write("List of duplicate files:\n");
	fd1.write("-"*60);
	
	for outer in l1:
		fd1.write("\n"+str(outer));
		count = 0;
		for inner in outer:
			count = count + 1;
			if count<2:
				pass;
			else:
				os.remove(inner);
				
	fd1.close();


def main():
	print("Automation script by Hemalata Choudhary");
	if len(sys.argv) != 2:
		print("Inavlid number of arguments");
	print("Application name: ",sys.argv[0]);
	
	if sys.argv[1] == '-h':
		print("This script displays checksum of all files in a directory");
		
	if sys.argv[1] == '-u':
		print("python Assignment11-1.py dirname");
	
	try:
		DuplicateFiles(sys.argv[1]);
	except Exception as E:
		print("Error: ",E);
		
	
	
if __name__ == "__main__":
	main();
	