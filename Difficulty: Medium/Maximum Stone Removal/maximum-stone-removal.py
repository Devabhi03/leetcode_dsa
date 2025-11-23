class Solution:
    def maxRemove(self, stones):
        parent = dict()
        def find(u):
            if parent.setdefault(u, u) != u:
                parent[u] = find(parent[u])
            return parent[u]
        
        for i, j in stones:
            parent[find(i)] = find(~j)
        
        comp = set(find(i) for i, _ in stones)
        return len(stones) - len(comp)
        