'''2. Write a recursive program which display below pattern.
Input : 5
Output : 1 2 3 4 5'''

def MyFunc(num):
    if (num!=0):
        no = num;
        num = num-1;
        MyFunc(num);
        print(no,end=" ");
        

def main():
    num = int(input("Enter a number: "));
    MyFunc(num);

if __name__ == "__main__":
    main();
