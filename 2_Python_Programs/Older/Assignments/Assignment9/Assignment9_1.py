'''
1.Write a program which accepts file name from user and check whether that file exists in
current directory or not.
Input : Demo.txt
Check whether Demo.txt exists or not.
'''
from sys import *;
import os;

def FileExist(file):
    if os.path.exists(file):
        print(file + " exists in the current directory");
    else:
        print(file + " does not exist in the current directory");

def main():
    if len(argv)<2:
        print("Invalid number of arguments");

    if argv[1] == "-h":
        print("This script checks if a file exists in current directory");
        print("Use -h or -u options for help and usage");

    if argv[1] == "-u":
        print("python FileExist.py demo.txt");
        print("FileExist.py is the script");
        print("demo.txt is the file name to check");

    FileExist(argv[1]);

if __name__ == "__main__":
    main();
