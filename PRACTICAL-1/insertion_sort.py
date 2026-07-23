a = input("Enter the numbers: ").split()
for i in range(len(a)):
    a[i] = int(a[i])
n = len(a)
for i in range(1, n):
    key = a[i]
    j = i - 1

    while j >= 0 and a[j] > key:
        a[j + 1] = a[j]
        j = j - 1

    a[j + 1] = key
print("Sorted numbers are:")
print(a)

