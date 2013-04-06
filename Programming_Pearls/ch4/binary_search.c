#include <stdio.h>

int binarySearch(int a[], int len, int key)
{
    int low, high, mid;
    low = 0;
    high = len - 1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursion(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid;
    mid = (low+high)/2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        binarySearchRecursion(a, mid+1, high, key);
    else
        binarySearchRecursion(a, low, mid-1, key);
}

int binarySearchFirstIndex(int a[], int len, int key)
{
    // 返回key最开始出现的的位置
    int low, high, mid;
    low = 0;
    high = len - 1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if(a[mid] < key)
            low = mid + 1;
        else
        {
            if (a[mid] == key)
            {
                 if (mid-1>=0 && a[mid-1]!=key || mid == 0)
                    return mid;
            }
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchLastIndex(int a[], int len, int key)
{
    int low, high, mid;
    low = 0;
    high = len - 1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (a[mid] <= key)
        {
            if (a[mid] == key)
            {
                if (mid+1<len && a[mid+1]!=key || mid==len-1)
                    return mid;
            }
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    //int a[] = {1,1,2,2,2,3,4,5,6,7,7,8,9,10,11};
    int a[] = {1,1,1,1};
    int len = sizeof(a) / sizeof(a[0]);
    int key = 1;
    int res;

    res = binarySearch(a, len, key);
    printf("[Binary-Search-Iteration] key:%d, index:%d\n", key, res);
    res = binarySearchFirstIndex(a, len, key);
    printf("[Binary-Search-First-Index] key:%d, index:%d\n", key, res);
    res = binarySearchLastIndex(a, len, key);
    printf("[Binary-Search-Last-Index] key:%d, index:%d\n", key, res);
    res = binarySearchRecursion(a, 0, len-1, key);
    printf("[Binary-Search-Recursion] key:%d, index:%d\n", key, res);

    return 0;
}
