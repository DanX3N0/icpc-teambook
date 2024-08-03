n = int(input())
data = list(map(int, input().split()))
 
nextValue = 0
ans = 0
 
for index in range(n - 1):
  value = data[index]
  nextValue = data[index + 1]
  if(value > nextValue):
    data[index + 1] = value
    ans += abs(value - nextValue) 
  
print(ans)