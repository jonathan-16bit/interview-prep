def longest_subarray_sum_k(arr, k):
    prefix_sum, max_len = 0, 0
    prefix_map = {}

    for i, n in enumerate(arr):
        prefix_sum += n

        # If subarray from 0 till i has sum k
        if prefix_sum == k:
            max_len = i + 1

        # Compute the needed prefix sum
        needed = prefix_sum - k

        # If we have seen this prefix sum before
        if needed in prefix_map:
            curr_len = i - prefix_map[needed]
            max_len = max(max_len, curr_len)

        # Store only the first (earliest) occurrence of prefix_sum
        if prefix_sum not in prefix_map:
            prefix_map[prefix_sum] = i

    return max_len

arr = [10, 5, 2, 7, 1, 9]
k = 15

print(longest_subarray_sum_k(arr, k))  # 4
