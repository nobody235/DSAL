class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return key % 10

    def linear_probing(self, key):
        index = self.hash_function(key)
        while self.table[index] is not None:
            index = (index + 1) % self.size
        return index

    def quadratic_probing(self, key, attempt):
        index = (self.hash_function(key) + attempt ** 2) % self.size
        return index

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            self.table[index] = (key, value)
            print(f"Inserted at index {index}")
        else:
            print(f"Collision occurred at index {index}")
            print("Applying linear probing to resolve the collision...")
            #attempt = 1
            while self.table[index] is not None:
                index = self.linear_probing(key)
                #attempt += 1
            self.table[index] = (key, value)
            print(f"Inserted at index {index}")

    def search_by_name(self, name):
        for i in range(self.size):
            if self.table[i] is not None and self.table[i][1] == name:
                return self.table[i][0]
        return None

    def display_table(self):
        print("Hash Table:")
        for i in range(self.size):
            if self.table[i] is not None:
                print(f"Index {i}: {self.table[i]}")


# Example usage
n = int(input("Enter the number of clients: "))
hash_table = HashTable(10)

for i in range(n):
    name = input(f"Enter the name of client {i + 1}: ")
    phone_number = int(input(f"Enter phone number {i + 1}: "))
    hash_table.insert(phone_number, name)

hash_table.display_table()

search_name = input("Enter the name to search: ")
result = hash_table.search_by_name(search_name)

if result is not None:
    print(f"The phone number for {search_name} is {result}.")
else:
    print(f"No phone number found for {search_name}.")