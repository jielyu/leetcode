"""
refer to: src/1276.cpp
"""

class Solution:
    # Runtime: 32 ms, faster than 60.46%
    # Memory Usage: 12.9 MB, less than 100.00%
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        # equations
        # 4x+2y=c1 & x+y=c2
        # formatted to 4x+2y=c1 & 2x+2y=2c2
        mid_val = tomatoSlices - 2*cheeseSlices
        # check integer solver for x
        if mid_val < 0 or mid_val % 2 == 1:
            return []
        x = int(mid_val / 2)
        y = cheeseSlices - x
        # check postive for y
        if y < 0:
            return []
        return [x, y]