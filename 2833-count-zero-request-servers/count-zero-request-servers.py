class Solution(object):
    def countServers(self, n, logs, x, queries):
        """
        :type n: int
        :type logs: List[List[int]]
        :type x: int
        :type queries: List[int]
        :rtype: List[int]
        """
        logs.sort(key = lambda log : log[1])
        indexed_queries = sorted([(q, i) for i, q in enumerate(queries)])

        res = [0] * len(queries)
        count = defaultdict(int)
        active_servers = 0
        left = 0
        right = 0
        for q_time, q_idx in indexed_queries:
            while right < len(logs) and logs[right][1] <= q_time:
                sid = logs[right][0]
                count[sid] += 1
                if count[sid] == 1:
                    active_servers += 1
                right += 1
            
            while left < len(logs) and logs[left][1] < q_time - x:
                sid = logs[left][0]
                count[sid] -= 1
                if count[sid] == 0:
                    active_servers -= 1
                left += 1
            
            # Total inactive servers = n - active
            res[q_idx] = n - active_servers
        
        return res