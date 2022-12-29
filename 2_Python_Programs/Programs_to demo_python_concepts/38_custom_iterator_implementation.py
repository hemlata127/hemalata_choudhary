class MyIterator:
	pos = None;
	l1 = []
	def __init__(self,l1):
		self.l1 = l1;
	def __iter__(self):
		self.pos = 0;
		return self;
	def __next__(self):
		if(self.pos<len(self.l1)):
			self.pos = self.pos+1;
			return self.l1[self.pos - 1];
		else:
			raise StopIteration;
			
arr = MyIterator([11,22,33,44]);
it = arr.__iter__();
print(it.__next__());
print(it.__next__());
print(it.__next__());
print(it.__next__());
print(it.__next__());