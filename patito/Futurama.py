badChars = "&%#@"

n, l = map(int, input().split())

sentence = input()

words = sentence.split()

badWords = 0

for word in words:
   cnt = 0
   
   for c in word:
      if c in badChars:
         cnt += 1
      
   if cnt > 0:
      badWords += 1

if(badWords <= l):
   print("Si se estrena")
else:
   print("Adios Futurama")