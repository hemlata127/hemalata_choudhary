def div(a,b):
	return (a//b);
	
def smart_div(func):
	def Inner(a,b):
		if(a<b):
			a,b = b,a;
		return func(a,b);
	return Inner;

div = smart_div(div);	

ans = div(2,5);
print(ans);