def maximum_sum_subarray_size_k(arr, k):
    if k <= 0 or len(arr) < k:
        return None

    # O(K) space
    window = sum(arr[:k])
    best = window

    # O(N) time
    for i in range(k, len(arr)):
        window -= arr[i - k]
        window += arr[i]
        best = max(best, window)

    return best
