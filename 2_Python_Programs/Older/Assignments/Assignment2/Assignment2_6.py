'''6. Write a program which accept one number and display below pattern.
Input : 5
Output :
* * * * *
* * * *
* * *
* *
*
'''

def Pattern(num):
    for i in range(num,0,-1):
        for i in range(i,0,-1):
            print("*",end = " ");
        print("");

def main():
    num = int(input("Enter a number: "));
    Pattern(num);

if __name__ == "__main__":
    main();
