values = [10, 25, 30, 35, 45, 55]
item = int(input("Enter the number to search: "))
for i in range(len(values)):
 if values[i] == item:
   print("index number ", i)
   break
else:
 print("ERROR")