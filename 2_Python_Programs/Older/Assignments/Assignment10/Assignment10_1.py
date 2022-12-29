'''
1.Design automation script which accept directory name and file extension from user. Display all
files with that extension.
Usage : DirectoryFileSearch.py “Demo” “.txt”
Demo is name of directory and .txt is the extension that we want to search.
'''

from sys import *
import os;
def DirectoryFileSearch(path,extension):
    if os.path.isdir(path) == False:
        print(path+" is not a directory");
        exit();
    
    if os.path.isabs(path) == False:
        path = os.path.abspath(path);

    for Folder, SubFolder, File in os.walk(path):
        
        for file in File:
            if file.endswith('.txt'):
                print(file);

def main():
    if len(argv)<2:
        print("Invalid number of arguments");
        print("Please use -h or -u options for help and usage");
        exit();

    if argv[1] == "-h" or argv[1] == "-H":
        print("This script searches files with specified extension in the specified directory");
        print("Please use -u option for usage");
        exit();

    if argv[1] == "-u" or argv[1] == "-U":
        print("Use the script in following way");
        print("python DirectoryFileSearch.py demo .txt");
        print("DirectoryFileSearch.py is the script name");
        print("demo is the directory to search");
        print(".txt is the file extension to look for");
        exit();

    DirectoryFileSearch(argv[1],argv[2]);
    

if __name__ == "__main__":
    main();
