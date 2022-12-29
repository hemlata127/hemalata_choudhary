'''10. Write a program which accept number from user and return addition of digits in that number.
Input : 5187934 Output : 37
'''

def SumOfDigits(num):
    result = 0;
    while(num!=0):
        result = result+(num%10);
        num=num//10;
    return result;
    

def main():
    num = int(input("Enter a number: "));
    ans = SumOfDigits(num);
    print(ans);
    
if __name__ == "__main__":
    main();
