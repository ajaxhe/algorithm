// 求数组中最长递增子序列
#include <stdio.h>
#include <stdlib.h>

int LIS(int arr[], int n)
{
    int i, j, cur, max_i, max;
    int* L = (int *)malloc(n*sizeof(int));
    memset(L, 0, n*sizeof(int));
    max = 0;
    for (i = 0; i < n; i++)
    {
        cur = arr[i];
        for (j = i; j < n; j++)
        {
            if (arr[j] >= cur)
            {
                L[i]++;
                cur = arr[j];
            }
        }
        printf("L[%d] = %d\n", i, L[i]);
        if (L[i] > max)
        {
            max = L[i];
            max_i = i;
        }
    }
    printf("start i: %d, len: %d\n", max_i, max);
    return max;
}

int main()
{
    int arr[] = {1,-1,0,-3,4,-5,6,-7};
    LIS(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
