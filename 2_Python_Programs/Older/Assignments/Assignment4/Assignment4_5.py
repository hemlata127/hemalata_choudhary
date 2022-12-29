'''5.Write a program which contains filter(), map() and reduce() in it. Python application which
contains one list of numbers. List contains the numbers which are accepted from user. Filter
should filter out all prime numbers. Map function will multiply each number by 2. Reduce will
return Maximum number from that numbers. (You can also use normal functions instead of
lambda functions).
Input List = [2, 70 , 11, 10, 17, 23, 31, 77]
List after filter = [2, 11, 17, 23, 31]
List after map = [4, 22, 34, 46, 62]
Output of reduce = 62'''

def AcceptList():
    num = int(input("Enter number of elements: "));
    NewList = list();
    for i in range(num):
        item = int(input("Enter number {} ".format(i+1)));
        NewList.append(item);
    return NewList;

def ChkPrime(num):
    if num == 2:
        return True;
    for i in range(2,num):
        if (num%i)==0:
            return False;
    return True

def FilterList(l):
    FilteredList = list();
    for i in range(len(l)):
        if (ChkPrime(l[i])==True):
            FilteredList.append(l[i]);
    return FilteredList;

def ModifyList(l):
    ModifiedList = list();
    for i in range(len(l)):
        ModifiedList.append(l[i]*2);
    return ModifiedList;

def MaxNumber(l):
    max = l[0];
    for i in range(len(l)):
        if l[i]>max:
            max = l[i]
    return max;

def main():
    NewList = AcceptList();
    print(NewList);
    FilteredList = FilterList(NewList);
    print(FilteredList);
    ModifiedList = ModifyList(FilteredList);
    print(ModifiedList);
    result = MaxNumber(ModifiedList);
    print(result);

if __name__ == "__main__":
    main();
