
class CartStack:
    def __init__(self):
        self.stack = []
    
    def add_to_cart(self, product):
        self.stack.append(product)
        print(f"{product} added to cart.")
    
    def undo_last_action(self):
        if self.stack:
            removed_product = self.stack.pop()
            print(f"Removed {removed_product} from cart.")
        else:
            print("No items to remove.")

# Example usage
cart_stack = CartStack()
cart_stack.add_to_cart("eBook: Machine Learning")
cart_stack.add_to_cart("Software: Video Editor")
cart_stack.undo_last_action()
