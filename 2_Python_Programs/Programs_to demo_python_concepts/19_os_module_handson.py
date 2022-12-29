import os;

def Main():
	#get current working directory
	print("The current working directory is: ",os.getcwd());
	#change directory
	os.chdir("C:\\2_PERSONAL_DATA\\2_javatpoint");
	print("The current workig directory now is: ",os.getcwd());
	#create directory
	os.mkdir("New_directory");
	os.chdir(os.getcwd() + "\\New_directory");
	print("Current working directory: ",os.getcwd());
	#create directory recursively
	str = os.getcwd() + "\\New_User";
	str = str + "\\Nikhil";
	os.makedirs(str);
	path = os.getcwd();
	dir = os.listdir(path);
	print(dir);
	os.rmdir("C:\\2_PERSONAL_DATA\\2_javatpoint\\New_directory\\New_User\\Nikhil");
	os.remove("C:\\2_PERSONAL_DATA\\2_javatpoint\\New_directory\\New_User\\test.txt");
	print(os.name);
	fd = open("test.txt",'r+');
	text = fd.read();
	print(text);
	fd.close();
	os.rename("test.txt","test1.txt");
	print(os.path.getsize("test1.txt"));

if(__name__ == "__main__"):
	Main();