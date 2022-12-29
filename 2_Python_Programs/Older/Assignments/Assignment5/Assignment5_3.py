'''3.Write a recursive program which display below pattern.
Input : 5
Output : 5 4 3 2 1'''

def MyFunc(num):
    if (num!=0):
        no = num;
        num = num-1;
        print(no,end=" ");
        MyFunc(num);     

def main():
    num = int(input("Enter a number: "));
    MyFunc(num);

if __name__ == "__main__":
    main();
