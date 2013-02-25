/*
* count the max value of sub-array
*/

#include <stdio.h>

int func1(int arr[], int n, int* head, int* tail)
{
    int i, max, sum, prehead;
    i = 0;
    // find the first element which great than 0
    max = 0;
    prehead = arr[0];
    while (arr[i] <= 0 && i < n)
    {
        if (arr[i] > max)
            max = arr[i];
        i++;
    }

    // all elements are less than 0
    if (i == n)
    {
        *head = prehead;
        *tail = arr[n-1];
        return max;
    }

    max = sum = 0;
    prehead = arr[i];
    while (i < n)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
            *head = prehead;
            *tail = arr[i];
            //printf("    i=%d, max=%d, sum=%d\n", i, max, sum);
        }
        else if (sum < 0)
        {
            //printf("    i=%d, max=%d, sum=%d\n", i, max, sum);
            ++i;
            while (arr[i] <= 0 && i < n)
                i++;
            sum = 0;
            prehead = arr[i];
            continue;
        }

        i++;
    }
    return max;
}

int func2(int arr[], int n, int* head, int* tail)
{
    int i, sum, max, prehead;

    sum = max = 0;
    prehead = arr[0];
    for (i=0; i<n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
            *head = prehead;
            *tail = arr[i];
        }
        else if (sum <= 0)
        {
            sum = 0;
            while (arr[i] <= 0)
                i++;
            prehead = arr[i];
            i--;
        }
    }
    if (max == 0)
    {
        *head = arr[0];
        *tail = arr[n-1];
    }

    return max;
}

int main()
{
/*
    int arr[] = {-2,5,3,-6,10,-8,6};
    //int arr[] = {-2,-5,-3,-6,-10,-8,-1};
    //int arr[] = {-2,11,-4,13,-5,-2};
    //int arr[] = {5,-8,3,2,5,0};
    //int arr[] = {10};
    //int arr[] = {-1,0,-2};
    int arr[] = {-10,1,2,3,4,-5,-23,3,7,-21};
*/
    int arr[10000];

    int result;
    int head, tail;
    int i, num;

/*
    result = func2(arr, sizeof(arr)/sizeof(arr[0]), &head, &tail);
    printf("%d %d %d\n", result, head, tail);
*/
    while (scanf("%d", &num)!=EOF)
    {
        if (!num)
            break;
        for (i=0; i<num; i++)
        {
            scanf("%d", arr+i);
        }
        result = func2(arr, num, &head, &tail);
        printf("%d %d %d\n", result, head, tail);
    }

    return 0;
}
