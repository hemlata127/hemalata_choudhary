'''Automation script which accept directory name from user and display all names of files
from that directory.'''

from sys import *;
import os;

def DirectoryWatcher(path):
    if os.path.isabs(path)==False:
        path = os.path.abspath(path);

    exists = os.path.isdir(path);
    if exists == False:
        print("Directory does not exist");

    for Folder,SubFolder,File in os.walk(path):
        print("Folder name is "+Folder);
        for subfol in SubFolder:
            print("Subfolder name is "+subfol);
        for file in File:
            print("File name is "+file);
    

def main():
    print("Directory Watcher Script : Version 1.0");
    if len(argv)<2:
          print("Error: Invalid number of arguments");
          print("Please refer option -h for help or -u for usage");
          exit();
    if argv[1] == '-h':
          print("This is a directory watcher script");
          exit();
    if argv[1] == '-u':
          print("Python DirectoryWatcher.py demo");
          print("DirectoryWatcher.py - name of the script");
          print("demo - path of the directory");
          exit();
    DirectoryWatcher(argv[1]);

if __name__ == "__main__":
    main();