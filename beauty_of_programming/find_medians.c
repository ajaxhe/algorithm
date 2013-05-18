// 寻找中位数
#include <stdio.h>

#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
#define PARENT(i) (i / 2);
#define MAXLINE 256

/* 使用最大堆和最小堆实现中位数的查找
参考链接：http://www.jishu521.com/post/imzooer/8010506.html
求数组中位数的方法：
用堆维护中位数的意思是说，设计两个堆，第一个堆(大顶堆)存放小于中位数的元素，第二个堆(小顶堆)存放大于中位数的元素。

下面是双堆维护中位数的语言描述：
1、初始化的时候设置两个变量分别记录两个堆【左堆和右堆】的元素的个数。
2、取第一个元素d[0]作为初始中位数m。
3、循环后面的每一个元素，如果比m大，则插入到右堆，如果比m小，则插入到左堆。
4、.如果此时最小堆和最大堆的元素个数的差值>=2 ，则将m加入到元素个数少的堆中，然后从元素个数多的堆将根节点赋值到m，最后重建两个最大堆和最小堆，返回到3。

此时，如果想要知道当前的中位数，若左右堆的元素个数相等，则输出左右堆顶元素的平均值，否则输出堆元素个数较大堆的堆顶元素。
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
            // 如果大顶堆元素个数-小顶堆元素个数=2，则删除大顶堆的首元素并将改元素添加到小顶堆中
            m = maxHeapPop(max_heap);
            minHeapInsert(min_heap, m);
        }
        else if (min_heap[0] - max_heap[0] == 2)
        {
            // 如果小顶堆元素个数-大顶堆元素个数=2，则删除小顶堆的首元素并将改元素添加到大顶堆中
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
    max_heap[0] = 0; // 初始化堆大小
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
