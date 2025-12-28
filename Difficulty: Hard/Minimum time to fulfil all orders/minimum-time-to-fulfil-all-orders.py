class Solution:
    def minTime(self, ranks, n):
        from heapq import heapify, heapreplace
        h = [(r, 1, r) for r in ranks]
        heapify(h)
        for _ in range(n - 1):
            total_time, donut_count, rank = h[0]
            heapreplace(h, (total_time + (donut_count + 1) * rank, donut_count + 1, rank))
        return h[0][0] 