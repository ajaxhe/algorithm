// insertion sort
#include <stdio.h>

void insertSort(int arr[], int len)
{
    int i, j;
    int key;
    for (j = 1; j < len; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}
void printArray(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    //int arr[] = {5,2,4,6,1,3};
    int arr[] = {31,41,59,26,41,58};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("original array:\n");
    printArray(arr, len);

    insertSort(arr, len);
    printf("after sort:\n");
    printArray(arr, len);

    return 0;
}
