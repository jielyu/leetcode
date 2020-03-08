"""
refer to: src/1353.cpp
"""

class Solution:
    # Runtime: 840 ms, faster than 85.92%
    # Memory Usage: 50.4 MB, less than 100.00%
    def maxEvents(self, events: List[List[int]]) -> int:
        # sort by increasing order of the end day
        events = sorted(events, key=lambda x : x[1])
        #print(events)
        # check all events 
        ret = 0
        used = [False for i in range(events[-1][1]+1)]
        for e in events:
            # find a free day to arrange this event
            for i in range(e[0], e[1]+1):
                if used[i]:
                    continue
                used[i] = True
                ret += 1
                # arrange current event completely
                break
        return ret