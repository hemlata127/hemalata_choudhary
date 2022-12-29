'''5. Write a recursive program which accept number from user and return its
factorial.
Input : 5
Output : 120'''

fact = 1;
def MyFunc(num):
    if (num!=0):
        global fact;
        fact=fact*num;
        num = num-1;
        MyFunc(num);
    
def main():
    num = int(input("Enter a number: "));
    MyFunc(num);
    print(fact);

if __name__ == "__main__":
    main();
