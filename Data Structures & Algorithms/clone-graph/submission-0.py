
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        clone = {}

        def cl(curr):
            if curr in clone:
                return clone[curr]
            
            copy = Node(curr.val)

            clone[curr] = copy

            for neigh in curr.neighbors:
                copy.neighbors.append(cl(neigh))

            return copy
    
        return cl(node)



