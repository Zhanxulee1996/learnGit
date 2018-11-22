def Max_Heapify(A, i, heapSize):
    l = 2*i+1
    r = 2*i+2
    if l < heapSize and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r < heapSize and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        Max_Heapify(A, largest, heapSize)


def Build_Max_Heap(A):
    heapSize = len(A)
    for i in range(int(heapSize/2)-1, -1, -1):
        Max_Heapify(A, i, heapSize)


def HeapSort(A):
    Build_Max_Heap(A)
    heapSize = len(A)
    for i in range(len(A)-1, 0, -1):
        A[0], A[i] = A[i], A[0]
        heapSize = heapSize-1
        Max_Heapify(A, 0, heapSize)

def Heap_Insert(A, key):
    A.append(key)
    i = len(A)-1
    j = int((i-1)/2)
    while i>0 and A[i] > A[j]:
        A[i], A[j] = A[j], A[i]
        i = j
        j = int((i-1)/2)


def Build_Max_Heap1(A):
    B = []
    for i in range(0, len(A)):
        Heap_Insert(B, A[i])
    return B


A = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
Build_Max_Heap(A)
# A = Build_Max_Heap1(A)
# HeapSort(A)
# two different ways to build max heap
print(A)
