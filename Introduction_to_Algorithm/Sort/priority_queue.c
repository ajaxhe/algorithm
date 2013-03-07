/*
use heap to achive priority queue
using queue[0] to store queue size
*/

#include <stdio.h>

#define LEFT(i) (i * 2)
#define RIGHT(i) (i * 2 + 1)
#define PARENT(i) (i / 2)
#define MAXLEN 256

void swap(int* i, int* j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void maxHeapify(int que[], int i)
{
    int l, r, max, len, temp;
    len = que[0];
    l = LEFT(i);
    r = RIGHT(i);
    if (l <= len && que[i] < que[l])
        max = l;
    else
        max = i;
    if (r <= len && que[max] < que[r])
        max = r;
    if (i != max)
    {
        swap(que+i, que+max);
        maxHeapify(que, max);
    }
}

int heapMaximum(int que[])
{
    return (que[1]);
}

int heapExtractMax(int que[])
{
    int res, len;
    len = que[0];
    if (len < 1)
    {
        printf("empty queue\n");
        return -1;
    }
    res = que[1];
    que[1] = que[len];
    que[0] = len - 1;
    maxHeapify(que, 1);

    return res;
}

void heapIncreaseKey(int que[], int i, int key)
{
    if (que[i] > key)
    {
        printf("que[%d]=%d must less than %d\n", i, que[i], key);
        return;
    }
    que[i] = key;
    while (i > 1 && que[PARENT(i)] < que[i])
    {
        swap(que+i, que+PARENT(i));
        i = PARENT(i);
    }
}

void maxHeapInsert(int que[], int key)
{
    int len = que[0] + 1;
    if (len >= MAXLEN)
    {
        printf("too many element in queue(maximum is: %d)", MAXLEN);
        return ;
    }
    que[0] = len;
    que[len] = key - 1;
    heapIncreaseKey(que, len, key);
}

void minHeapify(int que[], int i)
{
    int l, r, len, min, temp;
    len = que[0];
    l = LEFT(i);
    r = RIGHT(i);
    if (l <= len && que[i] > que[l])
        min = l;
    else
        min = i;
    if (r <= len && que[r] < que[min])
        min = r;

    if (min != i)
    {
        swap(que+i, que+min);
        minHeapify(que, min);
    }
}

int heapMinimum(int que[])
{
    return (que[1]);
}

int heapExtractMin(int que[])
{
    int len = que[0];
    if (len < 1)
    {
        printf("empty queue\n");
        return -1;
    }
    int res;
    res = que[1];
    que[1] = que[len];
    len--;
    que[0] = len;
    minHeapify(que, 1);
    return res;
}

void heapDecreaseKey(int que[], int i, int key)
{
    if (key > que[i])
    {
        printf("que[%d]=%d must great than %d");
        return;
    }
    que[i] = key;
    while (i > 1 && que[PARENT(i)] > que[i])
    {
        swap(que+i, que+PARENT(i));
        i = PARENT(i);
    }
}

void minHeapInsert(int que[], int key)
{
    int len = que[0];
    len++;
    if (len >= MAXLEN)
    {
        printf("too many element in queue\n");
        return;
    }
    que[0] = len;
    que[len] = key + 1;
    heapDecreaseKey(que, len, key);
}

int main()
{
    int a[] = {5,9,13,15,13,12,8,7,4,0,6,2,1};
    int len = sizeof(a) / sizeof(a[0]);
    int queue[MAXLEN];
    queue[0] = 0;
    int i, res;
    for (i = 0; i < len; i++)
    {
        maxHeapInsert(queue, a[i]);
        printf("%02d, maximum:%d\n", queue[0], heapMaximum(queue));
    }
    printf("extract maximum:\n");
    while ((res = heapExtractMax(queue)) != -1)
    {
        printf("%02d, maximum:%d\n", queue[0]+1, res);
    }
    printf("minimum priority queue:\n");
    for (i = 0; i < len; i++)
    {
        minHeapInsert(queue, a[i]);
        printf("%02d, minimum:%d\n", queue[0], heapMinimum(queue));
    }
    printf("extract minimum:\n");
    while ((res = heapExtractMin(queue)) != -1)
    {
        printf("%02d, minimum:%d\n", queue[0]+1, res);
    }
    return 0;
}
