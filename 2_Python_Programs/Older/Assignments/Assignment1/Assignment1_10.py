'''10. Write a program which accept name from user and display length of its name.'''

def NameLength(name):
    print("There are "+str(len(name))+" characters in your name.");

def main():
    name = input("Enter your name: ");
    NameLength(name);
            
if __name__ == "__main__":
    main();
