class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for i in range(0, k//2):
            for j in range(0, k):
                # print(i, j, end = "****")
                # print(x+k-i, j)
                grid[x+i][y+j], grid[x+k-i-1][y+j] = grid[x+k-i-1][y+j], grid[x+i][y+j]
        return grid 

# 1, 0, 3
# 10 11 12
# 20 21 22
# 30 31 32

# 0, 2, 2
# 02 03
# 12 13