'''2.Write a program which contains one lambda function which accepts two parameters and return
its multiplication.
Input : 4 3 Output : 12
Input : 6 3 Output : 18'''

fptr = lambda n1,n2:(n1*n2);
def main():
    n1 = int(input("Enter first number: "));
    n2 = int(input("Enter second number: "));
    print("Product of {} and {} is {}".format(n1,n2,fptr(n1,n2)));

if __name__ == "__main__":
    main();
