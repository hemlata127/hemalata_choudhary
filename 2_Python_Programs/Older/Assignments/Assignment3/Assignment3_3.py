'''3.Write a program which accept N numbers from user and store it into List. Return Minimum
number from that List.
Input : Number of elements : 4
Input Elements : 13 5 45 7
Output : 5'''
def AcceptList():
    n = int(input("Enter the number of elements in list: "));
    l = list();
    for i in range(n):
        item = int(input("Enter element "+str(i)+": " ));
        l.append(item);
    return l

def FindMin(l):
    min = l[0];
    size = len(l);
    for i in range(size):
        if l[i]<min:
            min=l[i];
    return min;

def main():
    NewList = AcceptList();
    min = FindMin(NewList);
    print("Minimum item in the list is {}".format(min));
    
if __name__ == "__main__":
    main();
