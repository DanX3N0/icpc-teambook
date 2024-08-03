import sys 
 
dna = input()
 
ans = 1
max = 1
previousVal = dna[0]
 
for index in range(1, len(dna)):
  currentValue = dna[index]
  if(previousVal == currentValue):
    max = max + 1
    if(ans < max):
      ans = max
  else:
    if(ans < max):
      ans = max
    previousVal = currentValue
    max = 1
 
print(ans)