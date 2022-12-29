'''
2. Design automation script which accept directory name and two file extensions from user.
Rename all files with first file extension with the second file extenntion.
Usage : DirectoryRename.py “Demo” “.txt” “.doc”
Demo is name of directory and .txt is the extension that we want to search and rename
with .doc.
After execution this script each .txt file gets renamed as .doc.
'''

from sys import *;
import os;

def ChangeFileExtension(path,extension1,extension2):
    if os.path.isdir(path) == False:
        print(path+" is not a directory");
        exit();

    if os.path.isabs(path) == False:
        path = os.path.abspath(path);

    for Folder, SubSfolder, File in os.walk(path):
        for file in File:
            if extension1 in file:
                file = Folder + "\\" + file;
                os.rename(file,os.path.splitext(file)[0]+extension2);                   

def main():
    if len(argv)<2:
        print("Invalid number of arguments");
        print("Please refer -h and -u options for help and usage");
        exit();

    if argv[1] == "-h" or argv[1] == "-H":
        print("This script changes extension of a file");
        print("Please use -u option for usage");
        exit();

    if argv[1] == "-u" or argv[1] == "-U":
        print("Use the script in following way:");
        print("python ChangeFileExtension.py demo .py .txt");
        print("ChangeFileExtension.py is the script name");
        print("demo is the directory to search");
        print(".py is first file extension to change");
        print(".txt is new file extension");
        exit();

    ChangeFileExtension(argv[1],argv[2],argv[3]);

if __name__ == "__main__":
    main();
