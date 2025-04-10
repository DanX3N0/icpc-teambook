s1, s2 = map(str, input().split())

if(s1 < s2):
   print(s1, "<", s2)
elif(s1 == s2):
   print(s1, "=", s2)
else:
   print(s1, ">", s2)
