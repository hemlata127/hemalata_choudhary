'''1.Write a program which contains one lambda function which accepts one parameter and return
power of two.
Input : 4 Output : 16
Input : 6 Output : 64'''

fptr = lambda n:(n**2);
def main():
    num = int(input("Enter a number: "));
    print("Square of {} is {}".format(num,fptr(num)));

if __name__ == "__main__":
    main();
