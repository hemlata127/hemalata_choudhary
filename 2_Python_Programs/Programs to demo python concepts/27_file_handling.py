fptr = open("test1.txt",'r+');
print(fptr.read());
for x in fptr.readlines():
	print(x,end="");

fptr.seek(0);

print(fptr.readline());
print(fptr.readline());
print(fptr.readline());
print("File pointer: ",fptr.tell());

print(fptr.readline());
fptr.write("Hello");
fptr.seek(0);
print(fptr.read());
fptr.close();