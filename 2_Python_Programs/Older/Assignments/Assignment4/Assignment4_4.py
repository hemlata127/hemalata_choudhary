'''4.Write a program which contains filter(), map() and reduce() in it. Python application which
contains one list of numbers. List contains the numbers which are accepted from user. Filter
should filter out all such numbers which are even. Map function will calculate its square.
Reduce will return addition of all that numbers.
Input List = [5, 2, 3, 4, 3, 4, 1, 2, 8, 10]
List after filter = [2, 4, 4, 2, 8, 10]
List after map = [4, 16, 16, 4, 64, 100]
Output of reduce = 204'''

def AcceptList():
    num = int(input("Enter number of elements: "));
    NewList = list();
    for i in range(num):
        item = int(input("Enter number {} ".format(i+1)));
        NewList.append(item);
    return NewList;

def FilterList(l):
    FilteredList = list();
    for i in range(len(l)):
        if ((l[i]%2)==0):
            FilteredList.append(l[i]);
    return FilteredList;

def ModifyList(l):
    ModifiedList = list();
    for i in range(len(l)):
        ModifiedList.append(l[i]**2);
    return ModifiedList;

def FindProduct(l):
    ans = 0;
    for i in range(len(l)):
        ans = ans+l[i];
    return ans;

def main():
    NewList = AcceptList();
    print(NewList);
    FilteredList = FilterList(NewList);
    print(FilteredList);
    ModifiedList = ModifyList(FilteredList);
    print(ModifiedList);
    result = FindProduct(ModifiedList);
    print(result);

if __name__ == "__main__":
    main();
