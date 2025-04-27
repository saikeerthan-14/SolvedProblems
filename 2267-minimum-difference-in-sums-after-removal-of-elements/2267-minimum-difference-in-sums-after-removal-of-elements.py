import heapq
class Solution:
    def minimumDifference(self, nums):
        n = len(nums) // 3  # calculate n because nums has size 3 * n

        # -------------------
        # Step 1: Process prefix sums (left sums)
        # -------------------
        left_heap = []  # Max heap (invert sign because heapq is minheap in Python)
        left_sum = 0  # Store current sum
        prefix_sums = []  # To store prefix sums for first part

        for i in range(2 * n):  # only need to process till index 2n - 1
            heapq.heappush(left_heap, -nums[i])  # push negative for max-heap
            left_sum += nums[i]

            # If heap size exceeds n, remove largest element
            if len(left_heap) > n:
                removed = -heapq.heappop(left_heap)
                left_sum -= removed

            # If heap has n elements, record the prefix sum
            if len(left_heap) == n:
                prefix_sums.append(left_sum)

        # -------------------
        # Step 2: Process suffix sums (right sums)
        # -------------------
        right_heap = []  # Min heap to maintain largest n elements
        right_sum = 0  # Store current sum
        min_diff = float('inf')  # Initialize answer as infinity

        j = len(prefix_sums) - 1  # pointer to match prefix_sums

        for i in range(3 * n - 1, n - 1, -1):
            heapq.heappush(right_heap, nums[i])  # push directly for min-heap
            right_sum += nums[i]

            # If heap size exceeds n, remove smallest element
            if len(right_heap) > n:
                removed = heapq.heappop(right_heap)
                right_sum -= removed

            # When heap has n elements, check the difference
            if len(right_heap) == n:
                diff = prefix_sums[j] - right_sum  # prefix sum at matching index
                min_diff = min(min_diff, diff)  # update minimum difference
                j -= 1  # move prefix pointer

        return min_diff  # return final minimum difference
