'''9. Write a program which display first 10 even numbers on screen.'''

def FirstTenEvenNumbers():
    for i in range(1,21):
        if i%2==0:
            print(i);

def main():
    FirstTenEvenNumbers();
            
if __name__ == "__main__":
    main();
