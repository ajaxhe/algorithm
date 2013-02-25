// 整数中1出现的次数
#include <stdio.h>

int count_1(int n)
{
    int low, high, cur;
    int count, factor;
    factor = 1;
    count = 0;
    while (n / factor)
    {
        low = n - n / factor * factor;
        high = n / factor / 10;
        cur = n / factor % 10;
        //printf("low = %d, high = %d, cur = %d\n", low, high, cur);
        if (cur == 0)
            count += high * factor;
        else if (cur == 1)
            count += high * factor + low + 1;
        else
            count += (high + 1) * factor;

        factor *= 10;
    }
    return count;
}

int main()
{
    int a, b, res, temp;
    while (scanf("%d", &a) != EOF)
    {
        scanf("%d", &b);
        if (a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        res = count_1(b);
        if (a != 0)
            a--;
        res -= count_1(a);
        printf("%d\n", res);
    }
    return 0;
}
