def maximum_sum_subarray_size_k(arr, k):
    if k <= 0 or len(arr) < k:
        return None

    st, en = 0, k - 1

    # O(K) space
    window = sum(arr[:k])
    best = window

    # O(N) time
    for i in range(k, len(arr)):
        window -= arr[i - k]
        window += arr[i]

        best = max(best, window)
        if best == window:
            st, en = i - k + 1, i

    return best, st, en

def main():
    arr = [4, -1, 2, 1, -5, 4, 8, -2]
    k = 3 

    res_tup = maximum_sum_subarray_size_k(arr, k)
    if res_tup is None:
        return
    best, st, en = res_tup

    print(f"Input array: {arr}")
    print(f"Window size: {k}")
    print(f"Maximum sum: {best}, for the subarray {arr[st:en+1]}")

main()
