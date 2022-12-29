'''
4.Write a program which accept two file names from user and compare contents of both the
files. If both the files contains same contents then display success otherwise display failure.
Accept names of both the files from command line.
Input : Demo.txt Hello.txt
Compare contents of Demo.txt and Hello.txt
'''

from sys import *;
import os;
import filecmp

def FileContent(file1,file2):
    if os.path.exists(file1) == False:
        print(file1 + " does not exist");
        exit();

    if os.path.exists(file2) == False:
        print(file2 + " does not exist");
        exit();

    if filecmp.cmp(file1,file2) == True:
        print("SUCCESS");
    else:
        print("NOT SUCCESSFUL");

def main():
    if len(argv)<2:
        print("Invalid number of arguments");

    if argv[1] == "-h":
        print("This script checks if a file exists in current directory");
        print("Use -h or -u options for help and usage");

    if argv[1] == "-u":
        print("python FileExist.py file1.txt file2.txt");
        print("FileContent.py is the script");
        print("file1.txt is the first file to compare");
        print("file1.txt is the second file to compare");

    FileContent(argv[1],argv[2]);

if __name__ == "__main__":
    main();
