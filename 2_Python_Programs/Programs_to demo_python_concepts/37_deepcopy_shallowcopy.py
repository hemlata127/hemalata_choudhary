import copy;

l1 = [[1,1,1],[2,2,2],[3,3,3]];
l2 = copy.copy(l1);
l3 = copy.deepcopy(l1);
print("l1: ",l1);
print("l2: ",l2);
print("l3: ",l3);
l1.append([4,4,4]);
print("After adding l1");
print("l1: ",l1);
print("l2: ",l2);
print("l3: ",l3);
l1[0][0] = 99;
print("After editing l1");
print("l1: ",l1);
print("l2: ",l2);
print("l3: ",l3);