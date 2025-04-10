n = int(input())
k = int(input())

div = k // n

if((div * n) + n - 1 > k):
   div -= 1

print(div)