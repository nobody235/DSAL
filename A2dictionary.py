class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class Dictionary:
    def __init__(self, size):
        self.size = 10
        self.hash_table = [None] * size

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        hash_value = self._hash(key)
        node = self.hash_table[hash_value]

        while node is not None:
            if node.key == key:
                node.value = value
                return
            node = node.next

        new_node = Node(key, value)
        new_node.next = self.hash_table[hash_value]
        self.hash_table[hash_value] = new_node

    def find(self, key):
        hash_value = self._hash(key)
        node = self.hash_table[hash_value]

        while node is not None:
            if node.key == key:
                return node.value
            node = node.next

        return None

    def delete(self, key):
        hash_value = self._hash(key)
        node = self.hash_table[hash_value]
        prev_node = None

        while node is not None:
            if node.key == key:
                if prev_node is None:
                    self.hash_table[hash_value] = node.next
                else:
                    prev_node.next = node.next
                return

            prev_node = node
            node = node.next

    def print_dictionary(self):
        for i in range(self.size):
            node = self.hash_table[i]
            while node is not None:
                print(f"Key: {node.key}, Value: {node.value}")
                node = node.next

def main():
    dictionary = Dictionary(10)

    while True:
        print("\nDictionary Operations:")
        print("1. Insert")
        print("2. Find")
        print("3. Delete")
        print("4. Print Dictionary")
        print("5. Exit")

        choice = input("Enter your choice (1-5): ")

        if choice == '1':
            key = input("Enter the key: ")
            value = input("Enter the value: ")
            dictionary.insert(key, value)
            print("Key-Value pair inserted.")

        elif choice == '2':
            key = input("Enter the key to find: ")
            value = dictionary.find(key)
            if value is not None:
                print(f"Value: {value}")
            else:
                print("Key not found.")

        elif choice == '3':
            key = input("Enter the key to delete: ")
            dictionary.delete(key)
            print("Key deleted.")

        elif choice == '4':
            print("\nDictionary:")
            dictionary.print_dictionary()

        elif choice == '5':
            break

        else:
            print("Invalid choice. Please try again.")


if __name__ == '__main__':
    main()
