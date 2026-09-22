// The program dynamically allocates an array, takes user input, Reverse the Position of the element in the array.
#include <stdio.h>
// Function to reverse an array
void reverseArray(int *arr, int size);
int main()
{
    printf("The program dynamically allocates an array, takes user input, Reverse the Position of the element in the array.\n");
    int size,i;
    int *arr; // Use a pointer for dynamic memory allocation

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Allocate memory dynamically
    arr = malloc(size * sizeof(int));

    // Check if malloc was successful
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the array: \n");
    for ( i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Call the function to reverse the array
    reverseArray(arr, size);

    printf("Reversed array: \n");
    for ( i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
   // printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
// Function to reverse an array
void reverseArray(int *arr, int size)
{
    int temp = 0,i;
    for ( i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}