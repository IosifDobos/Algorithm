// StackTest.java
// Linked list implementation of Stack

class Stack {
    
    class Node {
        int data;
        Node next;  
    }
    private Node top;
      
    public Stack()
    { 
        top = null;
    }
    
    //create a function which pop a node into the stack  
    public void push(int x) {
        Node  t = new Node();
        t.data = x;
        t.next = top;
        top = t;
    }

    // only to be called if list is non-empty.
    // Otherwise an exception should be thrown.
    public int pop(){
        if(top != null)
        {
            Node t = top;
            top = t.next;
            return t.data;
        }
        return 0;
        
    } 

    //method to check if the stack is empty
    public boolean isEmpty(){
       return top == null;
    }

    //function created to check if a node is already in the stack
    public boolean isMember(int x)
    {
        //create a while loop which will loop through the stack to check is a given node
        //is already in stack
        while(top != null)
        {
            //check if the passed variable within this fuction already exist in the stack
            if(x == top.data)
                return true;
            //move to the next node
            top = top.next;
            
        }
        return false;
        
        
    }

    //function to display the stack content
    public void display() {
        Node t = top;

        System.out.println("\nStack contents are:  ");
        
        while (t != null) {
            System.out.print(t.data + " --> ");
            t = t.next;
        }
        System.out.print(" NULL\n");
    }

}

//test the Stack class
public class StackTest
{
    public static void main( String[] arg){
        Stack s = new Stack();

        System.out.println("Stack is created\n");
        
        //pushing some data into the stack
        s.push(10); s.push(3); s.push(11); s.push(7);
        s.display();
        
        //pop a node from the stack
        int i = s.pop();
        System.out.println("\nJust popped " + i);
        s.display();
        
        //check if a given value is in the stack
        if(s.isMember(3))
            System.out.println("\nAlready in stack!\n");
        else
            System.out.println("\nNot in stack!\n");
    }
}

