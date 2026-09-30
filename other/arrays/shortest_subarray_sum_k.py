def shortest_subarray_sum_k(arr, k):
    prefix_sum = 0
    min_len = len(arr) + 1  # sentinel value
    prefix_map = {}

    for i, n in enumerate(arr):
        prefix_sum += n

        # arr[0:i+1] has sum k
        if prefix_sum == k:
            min_len = min(min_len, i + 1)

        needed = prefix_sum - k

        # if this prefix sum is seen before
        if needed in prefix_map:
            curr_len = i - prefix_map[needed]
            min_len = min(min_len, curr_len)

        # overwrite with latest occurrence of prefix_sum
        prefix_map[prefix_sum] = i

    return min_len

def main():
    arr = [2, 3, 1, 2, 4, 3]
    target = 7
    print(f"Minimum length: {shortest_subarray_sum_k(arr, target)}")

main()
