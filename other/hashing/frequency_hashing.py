def freqMap(arr):
    freq = {}
    for elt in arr:
        freq[elt] = freq.get(elt, 0) + 1
    return freq

def main():
    arr = [1, 2, 4, 8, 1, 6, 3, 2, 6, 4, 1, 2, 8, 2, 5, 6, 5, 1, 2, 1, 0, 2, 4]
    print(freqMap(arr))

main()
