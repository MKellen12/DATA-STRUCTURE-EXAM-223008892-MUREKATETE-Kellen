from collections import deque

# Implementing Queue for Order Management
class OrderQueue:
    def __init__(self):
        self.queue = deque()
    
    def add_order(self, order):
        self.queue.append(order)
        print(f"Order {order} added to the queue.")
    
    def process_order(self):
        if self.queue:
            order = self.queue.popleft()
            print(f"Processing order {order}.")
        else:
            print("No orders to process.")

# Example usage
order_queue = OrderQueue()
order_queue.add_order("eBook: Python Programming")
order_queue.add_order("Software: Antivirus Pro")
order_queue.process_order()


