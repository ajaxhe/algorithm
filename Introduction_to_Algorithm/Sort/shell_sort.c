/*
shell sort
*/
#include <stdio.h>

void shellSort(int arr[], int len)
{
    int i, j, gap, key;
    for (gap = len/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < len; i++)
        {
            key = arr[i];
            for (j = i; j >= gap && arr[j-gap] > key; j -= gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = key;
        }
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
    int a[] = {81,94,11,96,12,35,17,95,28,58,41,75,15};
    int len = sizeof(a) / sizeof(a[0]);
    printf("original array:\n");
    printArray(a, len);

    shellSort(a, len);
    printf("after shell sort:\n");
    printArray(a, len);

    return 0;
}
