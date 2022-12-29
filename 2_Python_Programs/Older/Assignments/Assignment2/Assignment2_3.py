'''3. Write a program which accept one number from user and return its factorial.'''

def Factorial(num):
    result = 1;
    for i in range(1,num+1):
        result = result*i;
    return result;

def main():
    num = int(input("Enter a number: "));
    result = Factorial(num);
    print(result);

if __name__ == "__main__":
    main();
