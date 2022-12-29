l1 = [1, 2, 3, 4, 5, 6];
#map function
print(list(map((lambda x: x*x),l1)));
#filter function
print(list(filter((lambda x: x%2==0),l1)));
