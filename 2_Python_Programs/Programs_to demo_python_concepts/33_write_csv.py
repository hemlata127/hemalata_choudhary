import csv;

data = [{'Rank': 'B', 'first_name': 'Parker', 'last_name': 'Brian'},     
{'Rank': 'A', 'first_name': 'Smith', 'last_name': 'Rodriguez'},    
{'Rank': 'C', 'first_name': 'Tom', 'last_name': 'smith'},    
{'Rank': 'B', 'first_name': 'Jane', 'last_name': 'Oscar'},     
{'Rank': 'A', 'first_name': 'Alex', 'last_name': 'Tim'}];

fptr = open("test.csv",'w');
fieldnames = ['first_name','last_name','Rank'];
writer = csv.DictWriter(fptr,fieldnames=fieldnames);
writer.writeheader();
writer.writerow({'Rank': 'B', 'first_name': 'Parker', 'last_name': 'Brian'});
writer.writerow({'Rank': 'A', 'first_name': 'Smith', 'last_name': 'Rodriguez'});
writer.writerow({'Rank': 'C', 'first_name': 'Tom', 'last_name': 'smith'});
writer.writerow({'Rank': 'B', 'first_name': 'Jane', 'last_name': 'Oscar'});

print("Writing completed");