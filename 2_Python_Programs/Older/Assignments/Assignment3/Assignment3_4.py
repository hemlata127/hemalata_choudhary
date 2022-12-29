'''4.Write a program which accept N numbers from user and store it into List. Accept one another
number from user and return frequency of that number from List.
Input : Number of elements : 11
Input Elements : 13 5 45 7 4 56 5 34 2 5 65
Element to search : 5
Output : 3'''
def AcceptList():
    n = int(input("Enter the number of elements in list: "));
    l = list();
    for i in range(n):
        item = int(input("Enter element "+str(i)+": " ));
        l.append(item);
    return l

def SearchElement(l, num):
    frequency = 0;
    size = len(l);
    for i in range(size):
        if (l[i] == num):
            frequency = frequency+1;
    return frequency;
    
def main():
    NewList = AcceptList();
    num = int(input("Enter element to search"));
    occurance = SearchElement(NewList,num);
    print("{} occurs {} times in {}".format(num,occurance,NewList));
    
if __name__ == "__main__":
    main();
