'''5.Write a program which accept one number for user and check whether number is prime or not.'''

def isPrime(num):
    for i in range(2,num):
        if num%i==0:
            return "false";
    return "true";

def main():
    num = int(input("Enter a number: "));
    result = isPrime(num);
    if result == "true":
        print("Is prime number");
    else:
        print("Is not a prime number");

if __name__ == "__main__":
    main();
