import csv;
fptr = open("samplecsv.csv",'r');
result = csv.reader(fptr,delimiter=',');
line_count = 0;
for x in result:
	if(line_count == 0):
		print(f"Column headers are {','.join(x)}");
		line_count = line_count + 1;
	else:
		print(x);
		line_count = line_count + 1;
print(f"Processed {line_count} lines");
