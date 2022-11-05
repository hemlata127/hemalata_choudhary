Script Name: Directory Watcher Script
Summary: This script lists all the files and folders of a directory recursively
Description: The script takes a directory name as command line argument. It also implements the command line options -h for displaying help and -u for displaying script usage. The script crawls through the specified directory and lists all the files and folders recursively.
Modules used: sys, os
Methods/attributes used: 
	sys.argv() - gives an array of command line arguments
	os.path.isabs() - checks if the specified path is an absolute path
	os.path.abspath() - converts the path to absolute path
	os.path.isdir() - checks if the specified file is a directory
	os.walk() - Generates filenames in directory tree by walking the tree either top-down or bottom-up 
	os.walk returns a generator - this generator creates 3 tuples
	tuple1 - current path
	tuple2 - folders in current path
	tuple3 - files in current path