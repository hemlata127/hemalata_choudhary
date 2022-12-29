Script Name: Duplicate File Removal
Decsription: 
	This script takes name of a directory as a parameter and removes all duplicate files in that directory recursively. The directory files are searched, checksum of each file is calculated. All additional files with same checksum are removed. It creates a list of files removed and adds it to a log file. The log file is then sent as an email attachment to the email address received as a parameter. The script also implements and handles the command line options -h for displaying the help and -u for displaying the usage
Modules used: sys, os, time, hashlib, schedule, datetime, urllib.request, email related modules
