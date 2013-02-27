/* 有序数组中数字n出现次数
给定一个单调递增有序数组A，给定一个数字N，试给出一个算法得到A中该数字N出现的次数。
http://t.jobdu.com/thread-98635-1-1.html
*/
#include <stdio.h>

int findN(int arr[], int n, int len)
{
    int left, right, mid, i, res;
    // first find n
    left = 0;
    right = len - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == n)
            break;
        else if (arr[mid] < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (left > right)
        return -1;

    res = 0;
    for (i = left; i <= right; i++)
    {
        if (arr[i] == n)
            res++;
    }
    return res;
}

int main()
{
    int arr[] = {1,2,2,3,3,3,3,4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int n = 1;
    int res = findN(arr, n, len);
    printf("The value of %d appear %d times.\n", n, res);
    return 0;
}
