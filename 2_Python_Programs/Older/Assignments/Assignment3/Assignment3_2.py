'''2.Write a program which accept N numbers from user and store it into List. Return Maximum
number from that List.
Input : Number of elements : 7
Input Elements : 13 5 45 7 4 56 34
Output : 56'''
def AcceptList():
    n = int(input("Enter the number of elements in list: "));
    l = list();
    for i in range(n):
        item = int(input("Enter element "+str(i)+": " ));
        l.append(item);
    return l

def FindMax(l):
    max = l[0];
    size = len(l);
    for i in range(size):
        if l[i]>max:
            max=l[i];
    return max;

def main():
    NewList = AcceptList();
    max = FindMax(NewList);
    print("Maximum item in the list is {}".format(max));
    
if __name__ == "__main__":
    main();
