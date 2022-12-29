'''
1.Design automation script which accept directory name and display checksum of all files.
Usage : DirectoryChecksum.py “Demo”
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
		
	for Folder,Subfolder,Files in os.walk(path):
		for name in Files:
			checksum = GetCheckSum(os.path.join(Folder,name));
			print(name+" "+checksum);


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
	
