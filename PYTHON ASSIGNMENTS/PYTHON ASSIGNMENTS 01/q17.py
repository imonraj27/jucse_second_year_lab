import heapq as hp

listy = [7, 3, -2, 69, 24, 11, 5, 6, 2, 1, 77]
hp.heapify(listy)


class PriorityQueue:
    def __init__(self, listy):
        self._listy = listy
        hp.heapify(self._listy)

    def pop(self):
        return hp.heappop(self._listy)

    def push(self, x):
        hp.heappush(self._listy, x)


p = PriorityQueue(listy=listy)
print(p.pop())
print(p.pop())
print(p.pop())
print(p.pop())
print(p.pop())
p.push(-1)
print(p.pop())
