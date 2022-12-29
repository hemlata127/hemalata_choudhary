'''
2. Write a program which accept file name from user and open that file and display the contents
of that file on screen.
Input : Demo.txt
Display contents of Demo.txt on console.
'''

from sys import *;
import os;

def FileContent(file):
    if os.path.exists(file) == False:
        print(file + " does not exist");
        exit();

    fobj = open(file,'r');
    print(fobj.read());
    fobj.close();

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
