// fibonacci

#include <stdio.h>

int arr[100] = {0};

int func1(int n)
{
    int i;
    if (n > 1)
        arr[n] = func1(n-1) + func1(n-2);
    return arr[n];
}

int func2(int n)
{
    int i;
    if (!arr[n])
        arr[n] = func1(n-1) + func1(n-2);
    return arr[n];
}

int main()
{
    int i, j;
    int num;

    while (scanf("%d", &num) != EOF)
    {
        if (!num)
            break;

        arr[0] = 0;
        arr[1] = 1;
        num = num * 2 - 1;

        func2(num);
        for (i = 1; i <= num; i++)
        {
            if (!(i%2))
                continue;
            for (j = 0; j < i-1; j++)
                printf("%d ", arr[j]);
            printf("%d\n", arr[j]);
        }
/*
        for (i = 1; i <= num; i++)
        {
            arr[i+1] = arr[i-1] + arr[i];
            if (!(i%2))
                continue;
            for (j = 0; j < i-1; j++)
                printf("%d ", arr[j]);
            printf("%d\n", arr[j]);
        }
    */
    }
}
