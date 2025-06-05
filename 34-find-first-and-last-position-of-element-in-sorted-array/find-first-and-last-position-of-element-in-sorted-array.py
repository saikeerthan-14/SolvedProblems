from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]: 
        def findLeft():
            l, r = 0, len(nums) - 1
            left_idx = -1
            while l <= r:
                mid = (l + r) // 2
                if nums[mid] < target:
                    l = mid + 1
                else:
                    r = mid - 1
                    if nums[mid] == target:
                        left_idx = mid
            return left_idx

        def findRight():
            l, r = 0, len(nums) - 1
            right_idx = -1
            while l <= r:
                mid = (l + r) // 2
                if nums[mid] > target:
                    r = mid - 1
                else:
                    l = mid + 1
                    if nums[mid] == target:
                        right_idx = mid
            return right_idx

        return [findLeft(), findRight()]