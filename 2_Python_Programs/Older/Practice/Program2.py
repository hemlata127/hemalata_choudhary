'''
LESSER OF TWO EVENS: Write a function that returns the lesser of two given numbers if both numbers are even, but returns the greater if one or both numbers are odd
lesser_of_two_evens(2,4) --> 2
lesser_of_two_evens(2,5) --> 5
'''

def fun(num1,num2):
    if num1%2==0 and num2%2==0:
        if num1>num2:
            return num2;
        else:
            return num1;
    else:
        if num1>num2:
            return num1;
        else:
            return num2;

def main():
    num1 = int(input("Enter first number: "));
    num2 = int(input("Enter second number: "));
    result = fun(num1,num2);
    print(result);

if __name__ == "__main__":
    main();
