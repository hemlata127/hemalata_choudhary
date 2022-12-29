'''8. Write a program which accept number from user and print that number of “*” on screen.'''

def Assignment8(num):
    for i in range(0,num):
        print("*");

def main():
    num = int(input("Enter a number: "));
    Assignment8(num);
            
if __name__ == "__main__":
    main();
