def merge(a, low, mid, high):
    i = low
    j = mid+1
    b = []
    while i <= mid and j <= high:
        if a[i] < a[j]:
            b.append(a[i])
            i = i+1
        else:
            b.append(a[j])
            j = j+1

    while i <= mid:
        b.append(a[i])
        i = i+1

    while j <= high:
        b.append(a[j])
        j = j+1

    a[low:high+1] = b


def Mergesort(a, low, high):
    mid = int((low+high)/2)
    if low < high:
        Mergesort(a, low, mid)
        Mergesort(a, mid+1, high)
        merge(a, low, mid, high)


a = [23, 56, 89, 2, 34, 45, 11, 76, 47, 23]
Mergesort(a, 0, 9)
print(a)
