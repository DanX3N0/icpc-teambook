t = int(input())

for _ in range(t):
   n = int(input())

   sum = 0

   num = list(map(int, input().split()))

   for el in num:
      sum += el

   print(sum)
   