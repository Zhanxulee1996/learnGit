def FindMaxAddSubarray(Array):
    maxSum = Array[0]
    leftIndex = 0
    rightIndex = 0
    for i in range(1, len(Array)):
        sum = 0
        for j in range(i, 0, -1):
            sum = sum + Array[j]
            if sum > maxSum:
                maxSum = sum
                leftIndex = j
                rightIndex = i
    return [leftIndex, rightIndex, maxSum]


Array = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
print(FindMaxAddSubarray(Array))
