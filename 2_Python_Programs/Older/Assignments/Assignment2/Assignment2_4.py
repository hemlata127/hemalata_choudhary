'''3. Write a program which accept one number from user and return its factorial.'''

def SumOfFactors(num):
    result = 0;
    for i in range(1,num):
        if num%i==0:
            result = result+i;
    return result;

def main():
    num = int(input("Enter a number: "));
    result = SumOfFactors(num);
    print(result);

if __name__ == "__main__":
    main();
