//merge sort
#include <stdio.h>

#define MAXLEN 128
int left[MAXLEN];
int right[MAXLEN];

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    for (i = 0; i < n1; i++)
        left[i] = arr[l+i];
    for (i = 0; i < n2; i++)
        right[i] = arr[m+i+1];

    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}
void mergeSort(int arr[], int l, int r)
{
    int q = (l + r) / 2;
    if (l < r)
    {
        mergeSort(arr, l, q);
        mergeSort(arr, q+1, r);
        merge(arr, l, q, r);
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
    int arr[] = {3,41,52,26,38,57,9,49};
    //int arr[] = {5,6,7,8,1,2,3,4};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("original array:\n");
    printArray(arr, len);

    mergeSort(arr, 0, len-1);
    printf("after sort:\n");
    printArray(arr, len);

    return 0;
}
