'''
3.Write a program which accept file name from user and create new file named as Demo.txt and
copy all contents from existing file into new file. Accept file name through command line
arguments.
Input : ABC.txt
Create new file as Demo.txt and copy contents of ABC.txt in Demo.txt
'''

from sys import *;
import os;

def FileContent(file):
    if os.path.exists(file) == False:
        print(file + " does not exist");
        exit();

    fobj1 = open(file,'r');
    fobj2 = open("Demo.txt","w");
    content = fobj1.read();
    fobj2.write(content);
    fobj1.close();
    fobj2.close();

def main():
    if len(argv)<2:
        print("Invalid number of arguments");

    if argv[1] == "-h":
        print("This script checks if a file exists in current directory");
        print("Use -h or -u options for help and usage");

    if argv[1] == "-u":
        print("python FileExist.py demo.txt");
        print("FileContent.py is the script");
        print("demo.txt is the file to display");

    FileContent(argv[1]);

if __name__ == "__main__":
    main();
