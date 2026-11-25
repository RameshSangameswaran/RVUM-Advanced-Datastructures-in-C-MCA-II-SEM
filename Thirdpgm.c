//
// Created by rvu on 11/25/26.
//
#include <stdio.h>
#include <time.h>
// Linear Search Function
int linearSearch(int arr[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}
// Binary Search Function
int binarySearch(int arr[], int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[1000], n, key;
    int i, result;
    clock_t start, end;
    double linearTime, binaryTime;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    // Linear Search Performance
    start = clock();
    result = linearSearch(arr, n, key);
    end = clock();
    linearTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    if(result != -1)
        printf("\nLinear Search: Element found at position %d", result + 1);
    else
        printf("\nLinear Search: Element not found");
    printf("\nLinear Search Time = %lf seconds\n", linearTime);
    // Binary Search Performance
    start = clock();
    result = binarySearch(arr, 0, n - 1, key);
    end = clock();
    binaryTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    if(result != -1)
        printf("\nBinary Search: Element found at position %d", result + 1);
    else
        printf("\nBinary Search: Element not found");
    printf("\nBinary Search Time = %lf seconds\n", binaryTime);
    // Comparison
    printf("\nPerformance Comparison:\n");
    if(binaryTime < linearTime)
        printf("Binary Search is faster.\n");
    else if(binaryTime > linearTime)
        printf("Linear Search is faster.\n");
    else
        printf("Both searches took approximately the same time.\n");
    return 0;
}