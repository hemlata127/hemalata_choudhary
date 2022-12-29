'''7. Write a program which accept one number and display below pattern.
Input : 5
Output : 1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
'''

def Pattern(num):
    for i in range(1,num+1):
        for i in range(1,num+1):
            print(i,end = " ");
        print("");

def main():
    num = int(input("Enter a number: "));
    Pattern(num);

if __name__ == "__main__":
    main();
