values = [13, 26, 39, 52, 65, 78, 91, 104, 117, 130]
item = int(input("Enter the number: "))
start = 0
end = len(values) - 1
while start <= end:
 middle = (start + end) // 2
 if values[middle] == item:
   print("Element found at index", middle)
   exit()
 elif values[middle] < item:
  start = middle + 1
 else:
  end = middle - 1
print("Error")