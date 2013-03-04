/*
http://t.jobdu.com/thread-98707-1-1.html
1��д��һ���㷨������1-n��ȫ����
2����֪һ������ΪN������A������ÿ��Ԫ����1-N֮����κ�һ��Ԫ�أ����������ظ�������Ϊһ�����У�д��һ���㷨���ɸ����е��ֵ������һ���С����磬A=[3 2 1 4]������һ����ΪA'=[3 2 4 1]��A'����һ����ΪA''=[3 4 1 2]���Դ����ơ�
http://blog.csdn.net/joylnwang/article/details/7064115
*/

#include <stdio.h>

void swap(char* array, unsigned int i, unsigned int j)
{
    char t = array[i];
    array[i] = array[j];
    array[j] = t;
}

// �ݹ�������е�ȫ����
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
    //fullPermutation(arr, len, 0); // �ݹ��ӡȫ����

    // �����ֵ������ȫ����
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
