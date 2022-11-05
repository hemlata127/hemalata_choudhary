Script Name: Duplicate File Removal
Decsription: This script takes name of a directory as a parameter and removes all duplicate files in that directory recursively.
	It creates a list of files removed and adds it to a log file. The log file is then sent as an email attachment to the email address received as a parameter.
Modules used: hashlib, schedule
Methods used:
	os.path.isdir()
	os.path.isabs()
	os.path.abspath()
	os.path.exists()
	os.walk()
	os.path.join()
	os.mkdir()
	hashlib.md5()

	