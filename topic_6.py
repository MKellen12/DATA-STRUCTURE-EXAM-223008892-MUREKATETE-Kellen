class TreeNode:
    def __init__(self, name):
        self.name = name
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

    def display_tree(self, level=0):
        print("  " * level + self.name)
        for child in self.children:
            child.display_tree(level + 1)

# Example usage
root = TreeNode("Products")
ebooks = TreeNode("eBooks")
software = TreeNode("Software")

ebooks.add_child(TreeNode("Python Programming eBook"))
ebooks.add_child(TreeNode("Data Science eBook"))

software.add_child(TreeNode("Antivirus Software"))
software.add_child(TreeNode("Video Editing Software"))

root.add_child(ebooks)
root.add_child(software)

root.display_tree()
