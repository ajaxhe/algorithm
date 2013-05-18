// Ѱ����λ��
#include <stdio.h>

#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
#define PARENT(i) (i / 2);
#define MAXLINE 256

/* ʹ�����Ѻ���С��ʵ����λ���Ĳ���
�ο����ӣ�http://www.jishu521.com/post/imzooer/8010506.html
��������λ���ķ�����
�ö�ά����λ������˼��˵����������ѣ���һ����(�󶥶�)���С����λ����Ԫ�أ��ڶ�����(С����)��Ŵ�����λ����Ԫ�ء�

������˫��ά����λ��������������
1����ʼ����ʱ���������������ֱ��¼�����ѡ���Ѻ��Ҷѡ���Ԫ�صĸ�����
2��ȡ��һ��Ԫ��d[0]��Ϊ��ʼ��λ��m��
3��ѭ�������ÿһ��Ԫ�أ������m������뵽�Ҷѣ������mС������뵽��ѡ�
4��.�����ʱ��С�Ѻ����ѵ�Ԫ�ظ����Ĳ�ֵ>=2 ����m���뵽Ԫ�ظ����ٵĶ��У�Ȼ���Ԫ�ظ�����Ķѽ����ڵ㸳ֵ��m������ؽ��������Ѻ���С�ѣ����ص�3��

��ʱ�������Ҫ֪����ǰ����λ���������Ҷѵ�Ԫ�ظ�����ȣ���������ҶѶ�Ԫ�ص�ƽ��ֵ�����������Ԫ�ظ����ϴ�ѵĶѶ�Ԫ�ء�
*/
int findMediansByHeap(int arr[], int max_heap[], int min_heap[]);

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(int h[], int i)
{
    int max, len;
    int l, r;
    len = h[0];
    max = i;
    l = LEFT(i);
    r = RIGHT(i);
    if (l <= len && h[max] < h[l])
        max = l;
    if (r <= len && h[max] < h[r])
        max = r;
    if (i != max)
    {
        swap(h+i, h+max);
        maxHeapify(h, max);
    }
}

void buildMaxHeap(int h[])
{
    int len, i;
    len = h[0];
    for (i = len/2; i > 0; i--)
    {
        maxHeapify(h, i);
    }
}

void maxHeapInsert(int heap[], int key)
{
    int i, p;
    heap[0]++;
    heap[heap[0]] = key;
    i = heap[0];
    p = PARENT(i);
    while (p > 0 && heap[p] < heap[i])
    {
        swap(heap+i, heap+p);
        i = p;
        p = PARENT(i);
    }
}

int maxHeapPop(int heap[])
{
    int max;
    max = heap[1];
    heap[1]=heap[heap[0]];
    heap[0]--;
    maxHeapify(heap, 1);
    return max;
}

void maxHeapSort(int heap[])
{
    int len, i;
    buildMaxHeap(heap);
    while ( (len = heap[0]) > 0)
    {
        swap(heap+1, heap+len);
        heap[0]--;
        maxHeapify(heap, 1);
    }
}

void minHeapInsert(int heap[], int key)
{
    int i, p;
    heap[0]++;
    heap[heap[0]] = key;
    i = heap[0];
    p = PARENT(i);
    while (p > 0 && heap[p] > heap[i])
    {
        swap(heap+i, heap+p);
        i = p;
        p = PARENT(i);
    }
}

void minHeapify(int h[], int i)
{
    int max, len, l, r;
    len = h[0];
    max = i;
    l = LEFT(i);
    r = RIGHT(i);
    if (l <= len && h[max] > h[l])
        max = l;
    if (r <= len && h[max] > h[r])
        max = r;
    if (i != max)
    {
        swap(h+i, h+max);
        minHeapify(h, max);
    }
}

int minHeapPop(int heap[])
{
    int min;
    min = heap[1];
    heap[1]=heap[heap[0]];
    heap[0]--;
    minHeapify(heap, 1);
    return min;
}

void buildMinHeap(int h[])
{
    int len, i;
    len = h[0];
    for (i = len/2; i > 0; i--)
    {
        minHeapify(h, i);
    }
}

void printArray(int a[])
{
    int len = a[0];
    int i;
    for (i = 1; i <= len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int findMediansByHeap(int arr[], int max_heap[], int min_heap[])
{
    int i, m;

    for (i = 1, m = arr[i]; i <= arr[0]; i++)
    {
        if(m < arr[i])
            minHeapInsert(min_heap, arr[i]);
        else
            maxHeapInsert(max_heap, arr[i]);

        if (max_heap[0] - min_heap[0] == 2)
        {
            // ����󶥶�Ԫ�ظ���-С����Ԫ�ظ���=2����ɾ���󶥶ѵ���Ԫ�ز�����Ԫ����ӵ�С������
            m = maxHeapPop(max_heap);
            minHeapInsert(min_heap, m);
        }
        else if (min_heap[0] - max_heap[0] == 2)
        {
            // ���С����Ԫ�ظ���-�󶥶�Ԫ�ظ���=2����ɾ��С���ѵ���Ԫ�ز�����Ԫ����ӵ��󶥶���
            m = minHeapPop(min_heap);
            maxHeapInsert(max_heap, m);
        }
    }
    if (max_heap[0] == min_heap[0])
        return ( (max_heap[1]+min_heap[1]) / 2);
    else if(max_heap[0] > min_heap[0])
        return max_heap[1];
    else
        return min_heap[1];
}

int main()
{
    //int arr[] = {0,10,20,30,40,50,60,70,200};
    int arr[] = {0,200,30,40,10,70,20,60};
    int len = sizeof(arr) / sizeof(arr[0]) - 1;
    arr[0] = len;
    int max_heap[MAXLINE];
    int min_heap[MAXLINE];
    int res;
    max_heap[0] = 0; // ��ʼ���Ѵ�С
    min_heap[0] = 0;

    printf("Original array:\n");
    printArray(arr);
    res = findMediansByHeap(arr, max_heap, min_heap);
    printf("After maximum heap sort, new array:\n");
    maxHeapSort(arr);
    arr[0] = len;
    printArray(arr);
    printf("The medians is: %d\n", res);

    return 0;
}
