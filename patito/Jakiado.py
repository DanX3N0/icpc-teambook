t = int(input())

minus = "abcdefghijklmnopqrstuvwxyz"
mayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
esp = "@._<>-"
nums = "0123456789"

for _ in range(t):

   fmin = False
   fesp = False
   fnums = False
   fmay = False

   data = input()

   for c in data:
      
      if(c in minus):
         fmin = True
      if(c in mayus):
         fmay = True
      if(c in esp):
         fesp = True
      if(c in nums):
         fnums = True

   if(fmin and fesp and fnums and fmay):
      print("Dale no te jackiaran esta vez.")
   else:
      print("No va dar Botas.")