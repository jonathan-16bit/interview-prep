arr = list(map(int, input().split()))

def moveZeros(arr):
    lo, hi = 0, 0
    while (hi < len(arr)):
        if (arr[hi] != 0):
            arr[lo], arr[hi] = arr[hi], arr[lo]
            lo += 1
        hi += 1

    return arr

print(moveZeros(arr))
