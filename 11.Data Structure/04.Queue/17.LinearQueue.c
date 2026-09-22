#define max 8

#include <stdio.h>
#include <stdlib.h>

int linearQueue[max];
int front=-1,rear=-1;

int isfull()
{
	return(rear==max-1);
}

int isEmpty()
{
	return((front==-1)||(rear==-1));
}

void enqueue(int x)
{
	if(isfull())
	{
		printf("\nThe queue is full");
		exit(-1);
	}
	if(isEmpty())
	{
		front=0;
		rear=0;
		linearQueue[rear]=x;
		printf("\n%d is enqueue",x);
	}
	else
	{
		linearQueue[++rear]=x;
		printf("\n%d is enqueue",x);
	}
}

int dequeue()
{
	int x;
	if(isEmpty())
	{
		printf("\nThe queue is empty");
		return(-1);
	}
	
	if(front==rear)
	{
		x=linearQueue[front];
		front=-1;
		rear=-1;
		printf("\nThe item %d is dequeued",x);
		return x;
	}
	
	x=linearQueue[front++];
	printf("\nThe item %d is dequeued",x);
	return x;
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("\nThe queue is empty");
	}
	else
	{
		printf("\nThe queue:");
		for(i=front;i<=rear;i++)
		{
			printf("%d,",linearQueue[i]);
		}
	}
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. enqueqe\n2. dequeue\n3. Check if Empty\n4. Check if Full\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueqe: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isEmpty())
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 4:
            	 if (isfull())
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}