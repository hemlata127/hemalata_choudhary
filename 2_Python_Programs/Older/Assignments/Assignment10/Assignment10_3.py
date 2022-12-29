'''
3. Design automation script which accept two directory names. Copy all files from first directory
into second directory. Second directory should be created at run time.
Usage : DirectoryCopy.py “Demo” “Temp”
Demo is name of directory which is existing and contains files in it. We have to create new
Directory as Temp and copy all files from Demo to Temp.
'''
from sys import *;
import os;
import shutil;

def DirectoryCopy(dir1, dir2):
    if os.path.isdir(dir1) == False:
        print(dir1+" is not a directory");
        
    if os.path.exists(dir2) == False:
        os.mkdir(dir2,mode=777);

    if os.path.isabs(dir1) == False:
        dir1 = os.path.abspath(dir1);

    for Folder, SubFolder, File in os.walk(dir1):
        for file in File:
            file = Folder+"\\"+file;
            shutil.copy(file,dir2);

              

def main():
    if len(argv)<2:
        print("Invalid number of arguments");
        print("Please use -h or -u options for help and usage");
        exit();

    if argv[1] == "-h" or argv[1] == "-H":
        print("This script copies all files from one directory to another");
        print("Please use -u option for usage");
        exit();

    if argv[1] == "-u" or argv[1] == "-U":
        print("python DirectoryCopy.py dir1 dir2");
        print("DirectoryCopy.py is the script name");
        print("dir1 is source directory");
        print("dir2 is destination directory");

    DirectoryCopy(argv[1],argv[2]);

if __name__ == "__main__":
    main();
