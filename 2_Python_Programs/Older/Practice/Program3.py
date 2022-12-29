'''Write a function takes a two-word string and returns True if both words begin with same letter'''
def fun(s1):
    s2 = s1.split();
    if s2[0][0]==s2[1][0]:
        return True;
    else:
        return False;

def main():
    s1 = input("Enter a two word string: ");
    l1 = len(s1.split());
    while l1!=2:
        print("Incorrect string");
        s1 = input("Enter a two word string: ");
        if len(s1.split())==2:
            l1 = 2;
            break;
    result = fun(s1);
    print(result);

if __name__ == "__main__":
    main();
