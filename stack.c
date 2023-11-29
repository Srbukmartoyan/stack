#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{ // Node structure for the singly linked list
    int data;
    struct Node *next;
} Node;

typedef struct
{ // Stack structure
    int size;
    Node *head;
} Stack;

Node *createNode(int data)
{ // creating a new node with the given data
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack *createStack()
{ // creating and initializing an empty stack
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack *stack)
{ // checking if the stack is empty
    return stack->head == NULL;
}

void push(Stack *stack, int data)
{
    Node *newNode = createNode(data);
    if (stack->head == NULL)
    { // if head is empty set the new node as the head of the stack
        stack->head = newNode;
    }
    else
    {
        Node *current = stack->head;
        while (current->next != NULL)
        {
            current = current->next; // Traverse to the end of the stack
        }
        current->next = newNode; // Set the next of the last node to the new node
    }
    stack->size++;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    Node *current = stack->head;
    if (current->next == NULL)
    { // Special case if the head is null
        int poppedElement = current->data;
        free(current);
        stack->head = NULL;
        stack->size--;
        return poppedElement;
    }
    // Traverse to the second-to-last node
    while (current->next != NULL && current->next->next != NULL)
    {
        current = current->next;
    }
    int poppedElement = current->next->data;
    // If there's only one node, update head to NULL
    if (current->next == NULL)
    {
        stack->head = NULL;
    }
    else
    {
        // Remove the last node
        free(current->next);
        current->next = NULL;
    }

    stack->size--;

    return poppedElement;
}

int peek(Stack *stack)
{ // peekong at the top element without removing it
    if (isEmpty(stack))
    {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    Node *current = stack->head;

    // Traverse to the last node
    while (current->next != NULL)
    {
        current = current->next;
    }

    return current->data;
}

int size(Stack *stack)
{
    return stack->size;
}

void print(Stack *stack)
{
    Node *current = stack->head;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void destroyStack(Stack *stack)
{ // Function to free the memory allocated for the stack
    while (stack->head != NULL)
    {
        Node *temp = stack->head;
        stack->head = temp->next;
        free(temp);
    }
    free(stack);
}

int main()
{
    Stack *stack = createStack();
    printf("size: %d\n", size(stack));
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    print(stack);
    printf("Stack size: %d\n", size(stack));
    printf("---------------------\n");
    // printf("Poped element : %d\n", pop(stack));
    // printf("Poped element : %d\n", pop(stack));
    // printf("Poped element : %d\n", pop(stack));
    // // printf("Poped element : %d\n", pop(stack));
    // print(stack);
    // printf("Stack size: %d\n", size(stack));
    printf("peeked element %d\n", peek(stack));
    destroyStack(stack);
    print(stack);

    return 0;
}