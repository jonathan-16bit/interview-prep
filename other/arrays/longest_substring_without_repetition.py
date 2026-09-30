def longest_substring_without_repetition(text):
    last_occ = {}
    lo, best = 0, 0
    for hi, c in enumerate(text):
        if last_occ.get(c, -1) >= lo:
            lo = last_occ[c] + 1
        best = max(best, hi - lo + 1)
        last_occ[c] = hi
    return best
