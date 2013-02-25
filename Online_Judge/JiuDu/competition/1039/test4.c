/*
* fabonacci
*/

#include <stdio.h>

long long fabonacci(int n)
{
    int i;
    long long pre, cur, next;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        pre = 0;
        cur = 1;

        while (--n > 0)
        {
            next = pre + cur;
            pre = cur;
            cur = next;
        }
        return cur;
    }
}

int main()
{
    int n;
    long long result;
    while (scanf("%d", &n) != EOF)
    {
        result = fabonacci(n);
        printf("%lld\n", result);
    }

    return 0;
}
