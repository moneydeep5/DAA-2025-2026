def quickSort(a):
    if len(a) <= 1:
        return a
    pivot = a[0]
    left = []
    right = []
    for i in range(1, len(a)):
        if a[i] <= pivot:
            left.append(a[i])
        else:
            right.append(a[i])
    return quickSort(left) + [pivot] + quickSort(right)
a = input("Enter the numbers: ").split()
for i in range(len(a)):
    a[i] = int(a[i])
a = quickSort(a)
print("Sorted numbers are:")
print(a)