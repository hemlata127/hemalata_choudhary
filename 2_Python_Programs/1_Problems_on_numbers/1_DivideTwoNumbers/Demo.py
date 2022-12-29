#Problem statement: Write a program that divides two numbers

#function definition
def Divide(no1, no2):
	#check divisor should not be 0
    if(no2 == 0):
        print("Invalid input for second number, cannot divide by 0");
    else:
        return (no1/no2);
    
#entry point function - first function in the program to be executed
def main():
    no1 = int(input("Enter first number:"));
    no2 = int(input("Enter second number:"));
    ans = Divide(no1,no2);
    print("Answer: ",ans);
    
if __name__ == "__main__":
    main();