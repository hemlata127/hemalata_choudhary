'''Write a program to check if a number is a prime number'''
from math import *;
def isPrime(num):
    if num%2==0 and num>2:
        return False;
    else:
        for i in range(3,(int(sqrt(num))+1),2):
            if num%i==0:
                return False;
        return True;

def main():
    num = int(input("Enter a number: "));
    result = isPrime(num);
    if result == True:
        print("{} is prime".format(num));
    else:
        print("{} is not prime".format(num));

if __name__ == "__main__":
    main();
