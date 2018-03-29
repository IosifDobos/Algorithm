#   This program is sorting a link list using sentinel code(dummy z node)
#   Program created by Iosif Dobos, C16735789
#   @Copyright, all rights are reserved
#   Compiler used: Atom; Language: Python

#creating a linkedList class used to sort our list
class SortedLL:
    #create a init method which is the constructor of the SortedLL class
    def __init__(self):
        self.dummy = Node(None, None)   # set the dummy node to point to itself
        self.dummy.next = self.dummy    # set dummy to point to next node
        self.head = Node(self.dummy, 'Head') #if list empty dummy points to the head of the list

    #create a function/method that print all nodes from our list
    def print_nodes(self):
        current = self.head #current points to head of the list

        #create a while loop that will print all nodes and runs until dummy points to current
        while current != self.dummy:
            print(current.data)
            current = current.next

    #create function insert that will pass a new node and check through the while loop
    #and store the new node in the right position
    def insert(self, value):
        new_node = Node(None, value)
        current = self.head
        #compare the new added node and place it in the right position
        while (current.next != self.dummy and value > current.next.data):
            current = current.next
        #after the node is place it in the right position set him to points to the new node
        new_node.next = current.next
        current.next = new_node

    #fuction that will delete a node from the list
    def remove(self, value):
        #check if list is emptu before remove a node
        if self.isEmpty():
            print("List is Empty, you dummy!")
            return
        #set head to points to current
        current = self.head
        #check if the calue exist in the list
        while (current.next.data != value and current.next != self.dummy):
            current = current.next

        # If we found the value remove and set current.next to points to the next node
        if current.next.data == value:
            current.next = current.next.next
        #if the value is not in the list print an error message
        else:
            print("\nValue not in the list, you dummy!\n")

    #create a function is empty to check is the list is empty
    def isEmpty(self):
        current = self.head
        #if current.next points to dummy node  then return true the list is empty otherwise return false
        if current.next == self.dummy:
            return True
        else:
            return False

#create a class for the Nodes and to the constructor method we pase the pointer and the data type
class Node:
    def __init__(self, node, data):
        self.data = data
        self.next = node


#create a SortedLL node
sorted_list = SortedLL()
#insert some values into the list
sorted_list.insert(1)
sorted_list.insert(4)
sorted_list.insert(2)
sorted_list.insert(6)
sorted_list.insert(5)
#print the values added in a sorted order
sorted_list.print_nodes()
print("\n")
#delete a certain node from the list
sorted_list.remove(5)
print("\n5 was removed from the list")
sorted_list.print_nodes()
print("\n")
#delete another node from the List
sorted_list.remove(2)
print("2 was removed from the list\n")
sorted_list.print_nodes()
