//Code:-

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int stack[SIZE];
int top = -1;
void push(int x) 
{
    if (top >= SIZE - 1) 
	{ 
        printf("\nError: Stack overflow\n");
        exit(-1);
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() 
{
    if (top < 0) 
	{
        printf("\nError: Stack underflow\n");
        exit(-1);
    } else 
	{
        int temp = stack[top];
        top--;
        return temp;
    }
}

void display()
{
	int i;
    if (top < 0) 
	{
        printf("Stack is Empty\n");
    } 
	else 
	{
        printf("Stack (Top to Bottom):\n");
        for (i = top; i >= 0; i--) 
		{
            printf("| %d", stack[i]);
            printf(" |\n");
        }
    }
}

int main() 
{
    int choice, x;

    do {
 	    printf("\n--- Queue Menu ---\n");
        printf("Enter 1 to push");
        printf("\nEnter 2 to pop");
        printf("\nEnter 3 to display");
        printf("\nEnter 4 to exit");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                x = pop();
                printf("Popped element is %d\n", x);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid choice\n");
        }
    } while (choice != 4);

    return 0;
}

//Output:-

/*
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 1
Enter the element to push: 2
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 1
Enter the element to push: 3
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 1
Enter the element to push: 4
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 1
Enter the element to push: 5
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 3
Stack (Top to Bottom):
| 5 |
| 4 |
| 3 |
| 2 |
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 2
Popped element is 5
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 3
Stack (Top to Bottom):
| 4 |
| 3 |
| 2 |
Enter 1 to push
Enter 2 to pop
Enter 3 to display
Enter 4 to exit
Your choice: 4
Exiting...
*/