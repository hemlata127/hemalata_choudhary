from abc import ABC;

class Polygon(ABC):
	def sides(self):
		pass;
		
class Triangle(Polygon):
	def sides(self):
		print("Triangle has 3 sides");
		
class Square(Polygon):
	def sides(self):
		print("Square has 4 sides");
		
class Hexagon(Polygon):
	def sides(self):
		print("Hexagon has 6 sides");
		
t1 = Triangle();
t1.sides();

s1 = Square();
s1.sides();

h1 = Hexagon();
h1.sides();
