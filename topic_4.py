class Node:
    def __init__(self, order_id, priority):
        self.order_id = order_id
        self.priority = priority
        self.left = None
        self.right = None

class BSTOrderQueue:
    def __init__(self):
        self.root = None
    
    def insert(self, order_id, priority):
        if self.root is None:
            self.root = Node(order_id, priority)
        else:
            self._insert(self.root, order_id, priority)

    def _insert(self, node, order_id, priority):
        if priority < node.priority:
            if node.left is None:
                node.left = Node(order_id, priority)
            else:
                self._insert(node.left, order_id, priority)
        else:
            if node.right is None:
                node.right = Node(order_id, priority)
            else:
                self._insert(node.right, order_id, priority)

    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(f"Order ID: {node.order_id}, Priority: {node.priority}")
            self.inorder_traversal(node.right)

# Example usage
bst_order_queue = BSTOrderQueue()
bst_order_queue.insert("Order_1", 2)
bst_order_queue.insert("Order_2", 1)
bst_order_queue.insert("Order_3", 3)

bst_order_queue.inorder_traversal(bst_order_queue.root)
