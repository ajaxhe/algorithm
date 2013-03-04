// heap sort
#include <stdio.h>

#define PARENT(i) (i >> 1)
#define LEFT(i) (i * 2)
#define RIGHT(i) (i * 1 + 1)

void maxHeapify(int arr[], int i, int len)
{
    int l, r, max;
    int temp;
    l = LEFT(i);
    r = RIGHT(i);
    if (l <= len && arr[l] > arr[i])
        max = l;
    else
        max = i;
    if (r <= len && arr[r] > arr[max])
        max = r;
    if (i != max)
    {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        maxHeapify(arr, max, len);
    }
}

void buildMaxHeap(int arr[], int len)
{
    int i;
    for (i = len / 2; i >= 1; i--)
    {
        maxHeapify(arr, i, len);
        //printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void minHeapify(int arr[], int i, int len)
{
    int min, l, r, temp;
    l = LEFT(i);
    r = RIGHT(i);
    if (l <= len && arr[l] < arr[i])
        min = l;
    else
        min = i;
    if (r <= len && arr[r] < arr[min])
        min = r;
    if (min != i)
    {
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        minHeapify(arr, min, len);
    }
}

void buildMinHeap(int arr[], int len)
{
    int i;
    for (i = len/2; i > 0; i--)
        minHeapify(arr, i, len);
}

void heapSort(int arr[], int len)
{
    int temp;
    buildMaxHeap(arr, len);
    while (len > 0)
    {
        printf("%d ", arr[1]);
        temp = arr[1];
        arr[1] = arr[len];
        arr[len] = temp;
        len--;
        maxHeapify(arr, 1, len);
    }
}

void heapSort2(int arr[], int len)
{
    int temp;
    buildMinHeap(arr, len);
    while (len > 0)
    {
        temp = arr[1];
        arr[1] = arr[len];
        arr[len] = temp;
        printf("%d ", arr[len]);
        len--;
        minHeapify(arr, 1, len);
    }
}

void printArray(int arr[], int len)
{
    int i;
    for (i = 1; i <= len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    //int arr[] = {0,16,14,10,8,7,9,3,2,4,1};
    int arr[] = {0,4,1,3,2,16,9,10,14,8,7};
    int len = sizeof(arr) / sizeof(arr[0]) - 1;
    printf("original array:\n");
    printArray(arr, len);

    printf("sort:\n");
    heapSort2(arr, len);
    printf("\n");

    printf("after sort, array:\n");
    printArray(arr, len);

    return 0;
}
