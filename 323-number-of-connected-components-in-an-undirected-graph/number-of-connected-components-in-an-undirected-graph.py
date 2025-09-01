class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        res = 0 
        graph = defaultdict(list)
        visited = set()

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def dfs(node):
            for nei in graph[node]:
                if nei not in visited:
                    visited.add(nei)
                    dfs(nei)

        for i in range(n):
            if i not in visited:
                res += 1
                visited.add(i)
                dfs(i)

        return res