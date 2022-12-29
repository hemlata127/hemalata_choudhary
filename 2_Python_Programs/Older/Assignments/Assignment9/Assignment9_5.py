'''
nd Hello.txt
5. Accept file name and one string from user and return the frequency of that string from file.
Input : Demo.txt Marvellous
Search “Marvellous” in Demo.txt
'''

from sys import *;
import os;
import filecmp

def FileContent(file1,string1):
    if os.path.exists(file1) == False:
        print(file1 + " does not exist");
        exit();

    count = 0;
    fobj = open(file1,'r');
    for i in fobj.readlines():
        if string1 in i:
            count = count+1;
    fobj.close();
    return count;
    

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
        print("demo is the string to count in file1");

    count = FileContent(argv[1],argv[2]);
    print(argv[2]+" appears "+str(count)+" times in "+argv[1]);

if __name__ == "__main__":
    main();
