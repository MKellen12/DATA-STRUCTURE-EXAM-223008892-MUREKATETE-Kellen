def selection_sort(products):
    n = len(products)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if products[j]['priority'] < products[min_idx]['priority']:
                min_idx = j
        products[i], products[min_idx] = products[min_idx], products[i]

# Example usage
products = [
    {"name": "eBook: Data Science", "priority": 3},
    {"name": "Software: Antivirus", "priority": 1},
    {"name": "eBook: Python", "priority": 2}
]

selection_sort(products)

print("Sorted Products based on Priority:")
for product in products:
    print(f"{product['name']} - Priority: {product['priority']}")
