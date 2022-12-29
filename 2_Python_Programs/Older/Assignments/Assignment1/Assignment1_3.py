'''6.Write a program which accept number from user and check whether that number is positive or
negative or zero.'''

def ChkNumber(num):
    if num == 0:
        print("You entered zero");
    elif num<0:
        print("You entered a negative number");
    else:
        print("You entered a positive number");

def main():
    num = input("Enter a number: ");
    ChkNumber(num);
    
if __name__ == "__main__":
    main();
