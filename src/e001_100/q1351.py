"""
refer to: src/1351.cpp
"""


class Solution:
    # Runtime: 124 ms, faster than 81.38%
    # Memory Usage: 14 MB, less than 100.00%
    def countNegatives(self, grid: List[List[int]]) -> int:
        ret = 0
        for row in grid:
            for v in row:
                if v < 0:
                    ret += 1
        return ret

class Solution02:
    # Runtime: 132 ms, faster than 31.87%
    # Memory Usage: 14 MB, less than 100.00%
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid) - 1, len(grid[0]) - 1
        end, ret = 0, 0
        while m >= 0:
            c = n
            while c >= end:
                if grid[m][c] < 0:
                    ret += 1
                else:
                    end = c + 1
                    break
                c -= 1
            if end > n:
                break
            m -= 1
        return ret

class Solution03:
    # Runtime: 120 ms, faster than 93.16%
    # Memory Usage: 13.7 MB, less than 100.00%
    def countNegatives(self, grid: List[List[int]]) -> int:
        ret = 0
        for row in grid:
            ret += len(list(filter(lambda x: x < 0, row)))
        return ret
    