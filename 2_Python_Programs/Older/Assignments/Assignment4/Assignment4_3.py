'''3.Write a program which contains filter(), map() and reduce() in it. Python application which
contains one list of numbers. List contains the numbers which are accepted from user. Filter
should filter out all such numbers which greater than or equal to 70 and less than or equal to
90. Map function will increase each number by 10. Reduce will return product of all that
numbers.
Input List = [4, 34, 36, 76, 68, 24, 89, 23, 86, 90, 45, 70]
List after filter = [76, 89, 86, 90, 70]
List after map = [86, 99, 96, 100, 80]
Output of reduce = 6538752000'''

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
        if ((l[i]>=70) and (l[i]<=90)):
            FilteredList.append(l[i]);
    return FilteredList;

def ModifyList(l):
    ModifiedList = list();
    for i in range(len(l)):
        ModifiedList.append(l[i]+10);
    return ModifiedList;

def FindProduct(l):
    ans = 1;
    for i in range(len(l)):
        ans = ans*l[i];
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
