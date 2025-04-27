import heapq
class Solution:
    def minimumDifference(self, nums):
        n = len(nums) // 3  # calculate n because nums has size 3 * n

        # -------------------
        # Step 1: Prepare prefix sums (left sums)
        # -------------------
        left_heap = []  # Max heap (invert sign because heapq is minheap in Python)
        left_sum = 0  # Store the current sum of selected elements
        prefix = [0] * len(nums)  # prefix[i] will store minimum sum of first n elements till index i

        for i in range(len(nums)):
            heapq.heappush(left_heap, -nums[i])  # push negative to simulate max heap
            left_sum += nums[i]  # add current number to left_sum

            # If heap size exceeds n, remove largest element
            if len(left_heap) > n:
                removed = -heapq.heappop(left_heap)  # pop from heap and invert sign
                left_sum -= removed  # subtract removed element from sum

            # If we have exactly n elements, store the sum at prefix[i]
            if len(left_heap) == n:
                prefix[i] = left_sum

        # -------------------
        # Step 2: Prepare suffix sums (right sums)
        # -------------------
        right_heap = []  # Min heap (direct push because we need largest elements)
        right_sum = 0  # Store the current sum of selected elements
        suffix = [0] * len(nums)  # suffix[i] will store maximum sum of last n elements from index i

        for i in range(len(nums) - 1, -1, -1):
            heapq.heappush(right_heap, nums[i])  # push directly because we want to remove smallest
            right_sum += nums[i]

            # If heap size exceeds n, remove smallest element
            if len(right_heap) > n:
                removed = heapq.heappop(right_heap)
                right_sum -= removed

            # If we have exactly n elements, store the sum at suffix[i]
            if len(right_heap) == n:
                suffix[i] = right_sum

        # -------------------
        # Step 3: Find the minimum difference
        # -------------------
        ans = float('inf')  # initialize answer to infinity

        # Try all possible splits where prefix ends at i and suffix starts at i+1
        for i in range(n - 1, 2 * n):
            diff = prefix[i] - suffix[i + 1]  # calculate difference
            ans = min(ans, diff)  # update minimum difference

        return ans  # return final answer