import re;
s1 = "Mary had a little lamb";
s2 = "She ses sea shells on the sea shore";
pattern1 = 'se*';
match_object = re.match(pattern1, s2);
print(match_object);
match_object = re.search(pattern1, s2s);
print(match_object);
match_object = re.findall(pattern1, s2);
print(match_object);