"""
refer to src/1282.cpp
"""

class Solution:
    # Runtime: 72 ms, faster than 95.14%
    # Memory Usage: 12.8 MB, less than 100.00%
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        d = {}
        for idx, v in enumerate(groupSizes):
            if v not in d:
                d[v] = [idx]
            else:
                d[v].append(idx)
        ret = []
        for k, vals in d.items():
            for i in range(len(vals) // k):
                ret.append(vals[i * k : (i + 1) * k])
        return ret
        
    # Runtime: 228 ms, faster than 5.69%
    # Memory Usage: 12.8 MB, less than 100.00%
    def groupThePeople_1(self, groupSizes: List[int]) -> List[List[int]]:
        n = len(groupSizes)
        ret = []          # to record all groups
        ret_limit = []    # to record limitation of groups
        succ = False;     # to mark if successful in inserting
        for i in range(n):
            s = groupSizes[i]
            length = len(ret)
            succ = False
            # insert current person into existing group
            for j in range(length):
                limit = ret_limit[j]
                # valid group
                if s == limit and limit > len(ret[j]):
                    ret[j].append(i)
                    succ = True
                    break
            # create a new group
            if not succ:
                ret_limit.append(s)
                ret.append([i])
        return ret