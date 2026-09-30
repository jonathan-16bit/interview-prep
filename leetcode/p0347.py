class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq = {}
        for n in nums:
            freq[n] = freq.get(n, 0) + 1

        freq = dict(sorted(freq.items(), key=lambda pair: pair[1], reverse=True))
        
        top_k = []
        count = 0
        for n, _ in freq.items():
            count += 1
            top_k.append(n)
            if count >= k: 
                break

        return top_k

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        return list(dict(sorted(Counter(nums).items(), key=lambda pair: pair[1], reverse=True)).keys())[:k]

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq = {}
        for n in nums:
            freq[n] = freq.get(n, 0) + 1

        buckets = [[] for _ in range(len(nums) + 1)]
        for n, count in freq.items():
            buckets[count].append(n)

        res = []
        for bucket in reversed(buckets):
            for n in bucket:
                res.append(n)

                if len(res) == k:
                    return res
