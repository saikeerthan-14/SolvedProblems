class MinStack:

    def __init__(self):
        self.stack = []
        self.min = float("-inf")

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append(val)
            self.min = val
        elif self.min >= val:
            self.stack.append(2*val-self.min)
            self.min = val
        else:
            self.stack.append(val)

    def pop(self) -> None:
        if self.min >= self.stack[-1]:
            self.min = 2*self.min - self.stack[-1]
        self.stack.pop()
        
    def top(self) -> int:
        if self.min >= self.stack[-1]:
            return self.min
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.min


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()