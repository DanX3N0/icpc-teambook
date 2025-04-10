a, b = map(int, input().split())

data = list(int(x) for x in input().split())

ans = 0

for e in data:
   if(e >= a and e <= b):
      ans += e

print(ans)