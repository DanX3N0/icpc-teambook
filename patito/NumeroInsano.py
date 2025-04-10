n = int(input())

ans = []

for t in range(n):
   a, b, c = map(int, input().split())

   if(a == b):
      ans.append("Luisin")
   elif(a == c):
      ans.append("Sami")
   else:
      ans.append("Herland")


for e in ans:
   print(e)