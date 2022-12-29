import random;

def Main():
	print(random.random());
	print("Random number between 1 and 500: ",random.randint(1,500));
	l1 = [10, 20, 304, 40, 30, 50, 60, 70, 80, 90, 1, 2, 3, 4, 5, 6, 7, 8, 9];
	print(random.choice(l1));
	print("l1 = ",l1);
	random.shuffle(l1);
	print("shuffled l1 = ",l1);
	random.shuffle(l1);
	print("shuffled l1 = ",l1);
	random.seed(2);
	l2 = [random.randint(1,500) for x in range(0,6)];
	print(l2);
	random.seed(2);
	l2 = [random.randint(1,500) for x in range(0,6)];
	print(l2);

if(__name__ == "__main__"):
	Main();