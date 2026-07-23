a = input("Enter the numbers: ").split()
for i in range(len(a)):
    a[i] = int(a[i])
n = len(a)
for i in range(n):
    for j in range(n - 1):
        if a[j] > a[j + 1]:
            temp = a[j]
            a[j] = a[j + 1]
            a[j + 1] = temp
print("Sorted numbers are:")
print(a)