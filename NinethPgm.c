#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
// Swap Function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Insert into Max Heap
void insert(int value)
{
    int i;
    heap[size] = value;
    i = size;
    size++;
    while(i != 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d\n", value);
}
// Heapify Function
void heapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < size && heap[left] > heap[largest])
        largest = left;
    if(right < size && heap[right] > heap[largest])
        largest = right;
    if(largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}
// Delete Root Element
void deleteRoot()
{
    if(size <= 0)
    {
        printf("Heap is Empty\n");
        return;
    }
    printf("Deleted Element: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}
// Display Heap
void display()
{
    int i;
    if(size == 0)
    {
        printf("Heap is Empty\n");
        return;
    }
    printf("Heap Elements: ");
    for(i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
// Heap Sort
void heapSort()
{
    int originalSize = size;
    while(size > 1)
    {
        swap(&heap[0], &heap[size - 1]);
        size--;
        heapify(0);
    }
    printf("Sorted Elements: ");
    for(int i = 0; i < originalSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
    size = originalSize;
}
int main()
{
    int choice, value;
    do
    {
        printf("\n===== MAX HEAP MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete Root\n");
        printf("3. Display Heap\n");
        printf("4. Heap Sort\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                display();
                break;
            case 4:
                heapSort();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 5);
    return 0;
}
// Created by rvu on 11/25/26.
//
