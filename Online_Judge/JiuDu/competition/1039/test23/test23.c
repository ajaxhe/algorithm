#include <stdio.h>
#include <stdlib.h>

void ouput_print(int *pa, int num, int res)
{
    int i;
    int bit_num;
    int a, b;

    a = b = 0;

    // find first bit of res which not equal 0
    for (i=0; i<32; i++)
    {
        if (res & (1<<i))
        {
            bit_num = i;
            break;
        }
    }

    for (i=0; num--; i++)
    {
        if (*(pa+i) & (1<<bit_num))
            a ^= *(pa+i);
        else
            b ^= *(pa+i);
    }

    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    printf("%d %d\n", a, b);
}

int main()
{
    int num, i;
    int* pa = (int *)malloc(1000000*sizeof(int));
    int res;

    while (scanf("%d", &num) > 0)
    {
        res = i = 0;
        while (i < num) {
            scanf("%d", pa+i);
            res ^= *(pa+i);
            i++;
        }

        ouput_print(pa, num, res);
    }

    return 0;
}
