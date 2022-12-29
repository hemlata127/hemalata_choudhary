'''4.Write a recursive program which accept number from user and return
summation of its digits.
Input : 879
Output : 24'''

sum = 0;
def MyFunc(num):
    if (num!=0):
        global sum;
        sum=(sum + (num%10));
        num = num//10;
        MyFunc(num);
    
def main():
    num = int(input("Enter a number: "));
    MyFunc(num);
    print(sum);

if __name__ == "__main__":
    main();
