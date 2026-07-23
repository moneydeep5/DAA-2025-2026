a = input("Enter the numbers: ").split()
for i in range(len(a)):
    a[i] = int(a[i])
n = len(a)
for i in range(n):
    small = i
    for j in range(i + 1, n):
        if a[j] < a[small]:
            small = j
    temp = a[i]
    a[i] = a[small]
    a[small] = temp
print("Sorted numbers are:")
print(a)