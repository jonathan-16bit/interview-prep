def three_sum_closest(arr, target):
    closest = arr[0] + arr[1] + arr[2]
    arr = sorted(arr)

    for i in range(0, len(arr) - 2):
        l, r = i + 1, len(arr) - 1
        while l < r:
            curr = arr[i] + arr[l] + arr[r]

            if abs(curr - target) < abs(closest - target):
                closest = curr

            if curr == target: return curr
            elif curr < target: l += 1
            else: r -= 1

    return closest

def main():
    nums = [-1, 2, 1, -4]
    target = 1
    print(three_sum_closest(nums, target))

main()
