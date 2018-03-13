class Queue:

    def __init__(self):
        self.arr = []

    def deQueue(self):
        self.arr.pop(0)

    def enQueue(self, value):
        self.arr.append(value)

    def isEmpty(self):
        return not self.arr


    def isMember(self, value):
        return value in self.arr

    def size(self):
        return len(self.arr)

    def __str__(self):
        string = ""

        for element in self.arr:
            string += " -> " + str(element)

        return string





# We create the Queue
queue = Queue()

print("\nIs the queue empty? " + str(queue.isEmpty()))
print("\nSize of the Queue: " + str(queue.size()))

print("\nLet's add 10 digits!")

# Add 10 digits
for i in range(0, 10):
    queue.enQueue(i)

# Printing the Queue

print("\nPrinting Items:")
print(queue)

print("\nSize of the Queue: " + str(queue.size()))

print("\nis 0 a member: " + str(queue.isMember(0)))

print("\nDeQueue One Element!")
queue.deQueue()

print("\nPrinting Items:")
print(queue)

print("\nis 0 a member: " + str(queue.isMember(0)))

print("\nIs the queue empty? " + str(queue.isEmpty()))
print("")
