// competition 1039, test 13
#include <stdio.h>

int func(int arr[], int n)
{
    int condidate, i, times;
    for (i = times = 0; i < n; i++)
    {
        if (times == 0)
        {
            condidate = arr[i];
            times = 1;
        }
        else
        {
            if (condidate == arr[i])
                times++;
            else
                times--;
        }
    }
    // the problem is come from, consider the fellow sequence:
    // 7
    // 1 2 3 4 5 5 5
    /*
    if (times > 1)
        return condidate;
        */
    // must judge the value again
    for (i = times = 0; i < n; i++)
    {
        if (arr[i] == condidate)
            times++;
    }
    if (times * 2 > n)
        return condidate;
    else
        return -1;
}

int main()
{
    int i, num, value, res;
    int arr[100000];
    while (scanf("%d", &num) != EOF)
    {
        if (!num)
            break;
        for (i = 0; i < num; i++)
            scanf("%d", arr+i);
        res = func(arr, num);
        printf("%d\n", res);
    }
}
