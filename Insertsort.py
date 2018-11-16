def Insertsort(a):
    for i in range(len(a)):
        j = i-1
        temp = a[i]
        while j >= 0 and a[j] > temp:
            a[j+1] = a[j]
            j = j-1
        a[j+1] = temp


a = [23, 56, 89, 2, 34, 45, 11, 76, 47, 23]
Insertsort(a)
print(a)