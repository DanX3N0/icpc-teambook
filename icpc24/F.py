n = int(input())

p0 = 1
p1 = 1

ans = 0

for i in range(n-1):
   ans = p0 + p1
   p0 = p1
   p1 = ans

if(n == 1 or n == 0):
   print(1)
else:
   print(ans)