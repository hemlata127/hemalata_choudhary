'''
Question1:
Use for, .split(), and if to create a Statement that will print out words that start with 's':
st = 'Print only the words that start with s in this sentence'''
st = 'Print only the words that start with s in this sentence';
for i in st.split():
    if i[0]=='s':
        print(i);

print("-"*25)

'''Question2: Use range() to print all the even numbers from 0 to 10.'''
l1 = [i for i in range(0,10) if i%2==0];
print(l1);

print("-"*25)

'''Question3: 
Use a List Comprehension to create a list of all numbers between 1 and 50 that are divisible by 3.'''
l2 = [i for i in range(0,50) if i%3==0];
print(l2);

print("-"*25)

'''Question4: Go through the string below and if the length of a word is even print "even!"
st = 'Print every word in this sentence that has an even number of letters'''

st = 'Print every word in this sentence that has an even number of letters';
for i in st.split():
    if (len(i)%2==0):
        print(i);

print("-"*25)

'''Question5: Write a program that prints the integers from 1 to 100.
But for multiples of three print "Fizz" instead of the number, and for the multiples of five print "Buzz".
For numbers which are multiples of both three and five print "FizzBuzz"'''

for i in range(1,100):
    if (i%3==0):
        if (i%5==0):
            print("FizzBuzz");
        else:
            print("Fizz");
    elif (i%5==0):
        print("Buzz");
    else:
        print(i);
        
