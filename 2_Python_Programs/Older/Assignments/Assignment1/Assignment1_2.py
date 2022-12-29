'''2. Write a program which contains one function named as ChkNum() which accept one
parameter as number. If number is even then it should display “Even number” otherwise
display “Odd number” on console.'''

def ChkNum():
    num = input("Enter a number: ");
    if int(num)%2==0:
        print(num+" is an even number.");
    else:
        print(num+" is an odd number.");

def main():
    ChkNum();

if __name__ == "__main__":
    main();
