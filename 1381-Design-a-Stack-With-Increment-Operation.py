class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.maxSize = maxSize
        self.increments = [0] * maxSize  # To handle the increment operation efficiently

    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        if not self.stack:
            return -1
        index = len(self.stack) - 1
        increment_value = self.increments[index]
        
        # Apply the increment to the current top element
        if index > 0:
            self.increments[index - 1] += increment_value  # Propagate the increment to the next element
        self.increments[index] = 0  # Reset the increment for the current element
        return self.stack.pop() + increment_value

    def increment(self, k: int, val: int) -> None:
        limit = min(k, len(self.stack)) - 1
        if limit >= 0:
            self.increments[limit] += val  # Increment the bottom k elements using increments array

# Example usage:
# obj = CustomStack(3)
# obj.push(1)
# obj.push(2)
# print(obj.pop())       # Output: 2
# obj.push(2)
# obj.push(3)
# obj.push(4)            # Stack size is limited to 3, so this operation won't add the element
# obj.increment(5, 100)  # Increment the bottom 3 elements by 100
# obj.increment(2, 100)  # Increment the bottom 2 elements by 100
# print(obj.pop())       # Output: 103
# print(obj.pop())       # Output: 202
# print(obj.pop())       # Output: 201
# print(obj.pop())       # Output: -1
