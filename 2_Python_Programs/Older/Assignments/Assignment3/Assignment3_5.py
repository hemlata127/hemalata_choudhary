'''5.Write a program which accept N numbers from user and store it into List. Return addition of all
prime numbers from that List. Main python file accepts N numbers from user and pass each
number to ChkPrime() function which is part of our user defined module named as
MarvellousNum. Name of the function from main python file should be ListPrime().
Input : Number of elements : 11
Input Elements : 13 5 45 7 4 56 10 34 2 5 8
Output : 54 (13 + 5 + 7 +2 + 5)'''
def AcceptList():
    n = int(input("Enter the number of elements in list: "));
    l = list();
    for i in range(n):
        item = int(input("Enter element "+str(i)+": " ));
        l.append(item);
    return l

def ChkPrime(num):
    if num == 2:
        return True;
    for i in range(2,num):
        if (num%i)==0:
            return False;
    return True;
    
def GetPrimeList(l):
    size = len(l);
    PrimeList = list();
    for i in range(size):
        if (ChkPrime(l[i]))==True:
            PrimeList.append(l[i]);
    return PrimeList;

def SumPrime(PrimeList):
    sum = 0;
    for i in range(len(PrimeList)):
        sum = sum + PrimeList[i];
    return sum;

def main():
    NewList = AcceptList();
    print(NewList);
    PrimeList = GetPrimeList(NewList)
    print(PrimeList);
    sum = SumPrime(PrimeList);
    print("Sum of prime numbers is {}".format(sum));
    
if __name__ == "__main__":
    main();
