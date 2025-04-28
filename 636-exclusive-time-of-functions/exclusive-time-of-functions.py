from typing import List

class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        # result[i] will hold the exclusive time for function i
        result = [0] * n
        
        # stack to keep track of function IDs currently running (most recent on top)
        stack = []
        
        # prev_time: the timestamp of the last processed log event
        prev_time = 0
        
        # Iterate through each log in chronological order
        for log in logs:
            # Split the log string into [id, type, timestamp]
            # log.split(':') returns a list of substrings by splitting on ':'
            fid_str, typ, time_str = log.split(':')
            fid = int(fid_str)         # convert function-id substring to int
            timestamp = int(time_str)  # convert timestamp substring to int
            
            if typ == "start":
                # If there's a function already running, add the time slice
                # since prev_time to now to its exclusive time
                if stack:
                    # current running function is stack[-1]
                    # it has been running from prev_time up to (but not including) timestamp
                    result[stack[-1]] += timestamp - prev_time
                # Push this new function onto the stack (it starts now)
                stack.append(fid)
                # Reset prev_time to this start, for the next interval
                prev_time = timestamp
            else:  # typ == "end"
                # Pop the function that just ended
                finished_fid = stack.pop()
                # It has been running from prev_time through timestamp inclusive
                # so add (timestamp - prev_time + 1)
                result[finished_fid] += timestamp - prev_time + 1
                # Next interval (if any) starts right after this timestamp
                prev_time = timestamp + 1
        
        return result