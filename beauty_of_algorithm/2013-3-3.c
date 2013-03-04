/*
http://t.jobdu.com/thread-98707-1-1.html
1、写出一个算法来生成1-n的全排列
2、已知一个长度为N的序列A，它的每个元素是1-N之间的任何一个元素，且两两不重复，称他为一个排列，写出一个算法生成该排列的字典序的下一排列。例如，A=[3 2 1 4]，则下一排列为A'=[3 2 4 1]，A'的下一排列为A''=[3 4 1 2]，以此类推。
http://blog.csdn.net/joylnwang/article/details/7064115
*/

#include <stdio.h>

void swap(char* array, unsigned int i, unsigned int j)
{
    char t = array[i];
    array[i] = array[j];
    array[j] = t;
}

// 递归输出序列的全排列
void fullPermutation(char* arr, int len, int index)
{
    int i;
    if (index >= len)
        printf("%s\n", arr);
    else
    {
        for (i = index; i < len; i++)
        {
            swap(arr, index, i);
            fullPermutation(arr, len, index+1);
            swap(arr, index, i);
        }
    }
}

void reverse(char arr[], int start, int end)
{
    if (start >= end)
        return;
    int len = start - end + 1;
    int i;
    for (i = 0; i <= len/2; i++)
    {
        swap(arr, start+i, end-i);
    }
}

int pre_permutation(char arr[], int len)
{
    int k, i, max, max_i;
    for (i = len-2; i >= 0; i--)
    {
        if (arr[i] > arr[i+1])
        {
            k = i;
            break;
        }
    }
    if (i < 0)
    {
        printf("%s is the first permutation\n", arr);
        return -1;
    }
    max_i = k + 1;
    max = arr[max_i];
    for (i = k+1; i < len; i++)
    {
        if (arr[i] < arr[k] && arr[i] > max)
        {
            max_i = i;
            max = arr[max_i];
        }
    }
    if (max_i < len)
    {
        swap(arr, k, max_i);
        reverse(arr, k+1, len-1);
    }
    return 0;
}

int next_permutation(char arr[], int len)
{
    int k, i, min, min_i;
    for (k = len-2; k >= 0; k--)
    {
        if (arr[k] < arr[k+1])
            break;
    }
    if (k < 0)
    {
        printf("%s is the last permutation\n", arr);
        return -1;
    }
    min = arr[k+1];
    min_i = k+1;
    for (i = k + 1; i < len; i++)
    {
        if (arr[i] > arr[k] && arr[i] < min)
        {
            min_i = i;
            min = arr[i];
        }
    }
    if (min_i < len)
    {
        swap(arr, k, min_i);
        reverse(arr, k+1, len-1);
    }
    return 0;
}

int main()
{
    int i = 1;
    char arr[] = "1234";
    int len = sizeof(arr) / sizeof(arr[0]) - 1;
    //fullPermutation(arr, len, 0); // 递归打印全排列

    // 按照字典序输出全排列
    printf("next_permutation demo:\n");
    do
    {
        printf("%02d: %s\n", i, arr);
        i++;
    } while (next_permutation(arr, len) >= 0);

    i = 1;
    printf("\npre_permutation demo:\n");
    do
    {
        printf("%02d: %s\n", i, arr);
        i++;
    }
    while (pre_permutation(arr, len) >= 0);

    return 0;
}
