def three_sum(arr):
    arr = sorted(arr)
    res = []

    for i in range(len(arr) - 2):
        if i > 0 and arr[i] == arr[i - 1]:
            continue
        l, r = i + 1, len(arr) - 1

        while l < r:
            total = arr[i] + arr[l] + arr[r]
            if total == 0:
                res.append([arr[i], arr[l], arr[r]])

                lv, rv = arr[l], arr[r]
                while l < r and arr[l] == lv: l += 1
                while l < r and arr[r] == rv: r -= 1

            elif total < 0: l += 1
            else: r -= 1

    return res

def main():
    arr = [1, -2, 3, 1, 1]
    print(three_sum(arr))

main()
