// n! (1<=n<=20)
#include <stdio.h>

int main()
{
    int n, i;
    long long res;
    while (scanf("%d", &n) != EOF)
    {
        for (i = res = 1; i <= n; i++)
            res *= i;
        printf("%lld\n", res);
    }
    return 0;
}
