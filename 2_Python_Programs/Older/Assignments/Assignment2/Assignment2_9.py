'''9. Write a program which accept number from user and return number of digits in that number.
Input : 5187934 Output : 7
'''

def NumberOfDigits(num):
    result = 0;
    while(num!=0):
        result = result+1;
        num=num//10;
    return result;
    

def main():
    num = int(input("Enter a number: "));
    ans = NumberOfDigits(num);
    print(ans);
    
if __name__ == "__main__":
    main();
