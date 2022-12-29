from Arithmetic import *;
def myFunc():
    num1 = int(input("Enter first number: "));
    num2 = int(input("Enter second number: "));
    result = Add(num1,num2);
    print(result);
    result = Sub(num1,num2);
    print(result);
    result = Multiply(num1,num2);
    print(result);
    result = Divide(num1,num2);
    print(result);

def main():
    myFunc();

if __name__ == "__main__":
    main();
