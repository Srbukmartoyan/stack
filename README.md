# Stack Implementation in C

This C program provides a simple implementation of a stack using a singly linked list. The stack supports basic operations such as push, pop, peek, and provides functions to check if the stack is empty and to get its size.

## Overview

The project consists of two main structures:

1. **Node Structure:**
   - Represents a node in the singly linked list.
   - Contains integer data and a pointer to the next node.

    ```c
    typedef struct Node {
        int data;
        struct Node *next;
    } Node;
    ```

2. **Stack Structure:**
   - Represents the stack with a size attribute and a pointer to the head node.

    ```c
    typedef struct {
        int size;
        Node *head;
    } Stack;
    ```

## Functions

- `createNode(int data)`: Creates a new node with the given data.
- `createStack()`: Creates and initializes an empty stack.
- `isEmpty(Stack *stack)`: Checks if the stack is empty.
- `push(Stack *stack, int data)`: Pushes an element onto the stack.
- `pop(Stack *stack)`: Pops an element from the stack.
- `peek(Stack *stack)`: Peeks at the top element without removing it.
- `size(Stack *stack)`: Returns the size of the stack.
- `print(Stack *stack)`: Prints the elements of the stack.
- `destroyStack(Stack *stack)`: Frees the memory allocated for the stack.

## Compilation and Usage

1. **Compilation:**
   - Compile the program using the following command:

    ```bash
    gcc -o stack stack.c
    ```

2. **Run the Program:**
   - Execute the compiled program:

    ```bash
    ./stack
    ```

## Example

```c
int main() {
    Stack *stack = createStack();
    printf("Size: %d\n", size(stack));
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    print(stack);
    printf("Stack size: %d\n", size(stack));
    printf("---------------------\n");
    printf("Peeked element: %d\n", peek(stack));
    destroyStack(stack);

    return 0;
}
