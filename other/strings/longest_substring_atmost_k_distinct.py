def longest_substring_atmost_k_distinct(text, k):
    freq = {}
    distinct, best = 0, 0

    l = 0
    for r, ch in enumerate(text):
        freq[ch] = freq.get(ch, 0) + 1
        # New distinct character
        if freq[ch] == 1: 
            distinct += 1

        # Until we get at most k unique characters in the window
        while distinct > k:
            freq[text[l]] -= 1
            # If a character is no longer in the window, decrement the count of distinct ones
            if freq[text[l]] == 0: 
                distinct -= 1
            l += 1

        best = max(best, r - l + 1)

    return best

def main():
    tests = [("eceba", 2), ("aa", 1)]
    for text, k in tests:
        print(f"Longest substring with atmost {k} distinct characters: {longest_substring_atmost_k_distinct(text, k)}")

main()
