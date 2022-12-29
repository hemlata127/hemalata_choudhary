'''2. Write a program which accept one number and display below pattern.'''

def myFunc(num):
    for i in range(0,num):
        for j in range (0,num):
            print("*",end = " ")
        print("");

def main():
    num = int(input("Enter a number: "));
    myFunc(num);

if __name__ == "__main__":
    main();
