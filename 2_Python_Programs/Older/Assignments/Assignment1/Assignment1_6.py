'''7. Write a program which contains one function that accept one number from user and returns
true if number is divisible by 5 otherwise return false.'''

def DivisibleByFive(num):
    if (num%5)==0:
        return true;
    else:
        return false;

def main():
    num = input("Enter a number: ");
    print(DivisibleByFive(int(num)));
    
if __name__ == "__main__":
    main();
