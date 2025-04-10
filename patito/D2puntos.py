import math

x1, y1, x2, y2 = map(float, input().split())

dist = math.sqrt(pow(abs(x1-x2), 2) + pow(abs(y1-y2), 2))

if(dist == 0.0):
   print("0.00")
else:
   print(round(dist, 2))