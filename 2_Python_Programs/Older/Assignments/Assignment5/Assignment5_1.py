'''1. Write a recursive program which display below pattern.
Input : 5
Output : * * * * *'''

def MyFunc(num):
    if (num!=0):
        print("*",end=" ");
        num = num-1;
        MyFunc(num);

def main():
    num = int(input("Enter a number: "));
    MyFunc(num);

if __name__ == "__main__":
    main();
