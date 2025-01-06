class ProductArray:
    def __init__(self):
        self.products = []
    
    def add_product(self, product):
        self.products.append(product)
        print(f"Product {product} added to the catalog.")
    
    def display_products(self):
        print("Products available:")
        for product in self.products:
            print(product)

# Example usage
product_array = ProductArray()
product_array.add_product("eBook: Learn Python")
product_array.add_product("Software: Photoshop")
product_array.display_products()

