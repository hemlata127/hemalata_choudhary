'''1.Write a program which accept N numbers from user and store it into List. Return addition of all
elements from that List.
Input : Number of elements : 6
Input Elements : 13 5 45 7 4 56
Output : 130'''
def AcceptList():
    n = int(input("Enter the number of elements in list: "));
    l = list();
    for i in range(n):
        item = int(input("Enter element "+str(i)+": " ));
        l.append(item);
    return l;

def CalculateSum(l):
    sum = 0;
    for i in range(len(l)):
        sum = sum + l[i];
    return sum;

def main():
    NewList = AcceptList();
    sum = CalculateSum(NewList);
    print("Sum of items in the list is {}".format(sum));
    
if __name__ == "__main__":
    main();
