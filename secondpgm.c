#include <stdio.h>
int main()
{
    int arr[100], n, i, j, temp;
    int pos, element;
    // Input array elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Traversal//
    printf("\nArray Elements (Traversal): ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // Insertion
    printf("\n\nEnter position for insertion (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &element);
    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    n++;
    printf("\nArray after insertion: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // Deletion
    printf("\n\nEnter position for deletion (1 to %d): ", n);
    scanf("%d", &pos);
    for(i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("\nArray after deletion: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n\nArray after Bubble Sort: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// Created by rvu on 11/25/26.
//
