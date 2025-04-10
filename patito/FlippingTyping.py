wordsToLeft = "qwertasdfgzxcvb"
wordsToRight = "yuiophjklnm"

n = int(input())

ans = []

for i in range(n):
   
   word = input()

   cntL = 0
   cntR = 0
   fl = False

   for c in word:

      if(c in wordsToLeft):
         cntL += 1
         cntR = 0
      elif c in wordsToRight:
         cntR += 1
         cntL = 0

      if(cntL == 2 or cntR == 2):
         fl = True
         break
      
   if fl == True:
      ans.append("No")
   else:
      ans.append("Si")
   

for e in ans:
   print(e)