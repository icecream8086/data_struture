#include <stdio.h>

#define bool int
#define MAX_STUDENT 3
#define MAX_SIZE 100

void beauty_print()
{
    char line[81] = "";
    for (int i = 0; i < 80; i++)
    {
        line[i] = '*';
    }
    printf("%s\n", line);
}
typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

void init_stack(Stack *stack)
{
    stack->top = 0;
}

bool is_empty(Stack *stack)
{
    return stack->top == 0;
}


bool is_full(Stack *stack)
{
    return stack->top == MAX_SIZE;
}


void push(Stack *stack, int value)
{
    if (is_full(stack))
    {
        printf("Stack is full\n");
    }else{
            stack->data[stack->top++] = value;
    }
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }else{
        return stack->data[--stack->top];
    }
}
int get_top(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }else{
        return stack->data[stack->top - 1];
    }
}

int main()
{
    int pop_count_0 = 0;
    Stack stack;
    init_stack(&stack);
    push(&stack, 10);    
    push(&stack, 20);    
    push(&stack, 30);    
    push(&stack, 40);    
    push(&stack, 50);
    printf("Top element: %d\n", get_top(&stack));    
    pop_count_0 = pop(&stack);
    if (pop_count_0!=-1)
    {
        printf("Pop element: %d\n", pop_count_0);
    }
    printf("Top element: %d\n", get_top(&stack));
    beauty_print();
}
