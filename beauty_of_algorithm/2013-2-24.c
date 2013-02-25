/* �����鰴����ż˳������
����һ������A���Խ����Ϊ��������ż�����ҵ���ʽ������A=[12,8,7,5,6,11]����任���A'=[11,5,7,8,6,12]
ֻ��Ҫ��������ż�����ɣ�����Ҫ����
http://t.jobdu.com/thread-98631-1-1.html
*/

#include <stdio.h>

void mySort(int arr[], int n)
{
    int temp, i, j;
    i = 0;
    j = n - 1;
    while (i < j)
    {
        while ( (i < j) && (arr[i]%2 == 1) ) i++;
        while ( (i < j) && (arr[j]%2 == 0) ) j--;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {12,8,7,5,6,11};
    //int arr[] = {2,1,3,5,7,9};
    int num = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array:\n");
    printArray(arr, num);

    printf("After sort:\n");
    mySort(arr, num);
    printArray(arr, num);

    return 0;
}
