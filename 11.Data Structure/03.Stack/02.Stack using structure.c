//Code:-

#define MAX 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int items[MAX];
    int top;
}Stack;

void push(Stack *s, int value);
int pop(Stack *s);
void display( Stack *s);


int main()
{
    Stack s;
    s.top = -1;

    int choice, value;

    while (1) 
	{
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}

void push(Stack *s, int value)
{
    if (s->top == MAX - 1) 
	{
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(Stack *s) 
{
    if (s->top == -1) 
	{
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void display(Stack *s) 
{
	int i;
    if (s->top == -1) 
	{
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (i = s->top; i >= 0; i--) 
	{
        printf("|%d|\n", s->items[i]);
    }
}

//Output:-

/*

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 2
Pushed 2 onto the stack.

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 3
Pushed 3 onto the stack.

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 4
Pushed 4 onto the stack.

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 5
Pushed 5 onto the stack.

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements (top to bottom):
|5|
|4|
|3|
|2|

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped value: 5

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements (top to bottom):
|4|
|3|
|2|

--- Stack Menu ---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting program.
*/