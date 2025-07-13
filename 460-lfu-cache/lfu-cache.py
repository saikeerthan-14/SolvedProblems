class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = None
        self.next = None
    
class DLL:
    def __init__(self):
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0
    
    def insert(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next = node
        node.next.prev = node
        self.size += 1
    
    def remove(self, node):
        node.next.prev = node.prev
        node.prev.next = node.next
        self.size -= 1
    


from collections import defaultdict

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.minf = 0
        self.freq = defaultdict(DLL)
        self.cache = {}

    def get(self, key: int) -> int:
        # print(key)
        # print(self.cache.items())
        if key not in self.cache:
            return -1
        return self.updateCache(self.cache[key], key, self.cache[key].val)

    def updateCache(self, node, key, value):
        node = self.cache[key]
        node.val = value
        # print(node, node.key, node.val)
        old_freq = node.freq
        node.freq += 1
        # print("chae ")
        self.freq[old_freq].remove(node)
        self.freq[node.freq].insert(node)
        # print("chae ")
        if old_freq == self.minf and self.freq[old_freq].size == 0:
            self.minf += 1
        # print("chae ", node, node.val)
        
        return node.val

    def put(self, key: int, value: int) -> None:
        # print(key, value)
        if not self.capacity:
            return
        
        if key in self.cache:
            self.updateCache(self.cache[key], key, value)
        else:
            if len(self.cache) == self.capacity:
                lru = self.freq[self.minf].tail.prev
                self.freq[self.minf].remove(lru)
                del self.cache[lru.key]
            
            node = Node(key, value)
            self.cache[key] = node
            self.freq[1].insert(node)
            self.minf = 1
        
 