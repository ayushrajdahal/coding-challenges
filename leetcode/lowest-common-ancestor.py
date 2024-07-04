class Node:
    def __init__(self, left, right):
        self.left = left
        self.right = right

class Solution:
    def isEmpty(root):
        if not root.left and root.right:
            return True
    def findLeaves(root):
        if not isEmpty(root.left) and isEmpty(root.right):
            return findLeaves
