// 求二进制数中1的个数
#include <stdio.h>

int count1(unsigned x) {
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);

    return x;
}

int main()
{
    int n, res;
    n = 0x11011001;
    res = count1(n);
    printf("the result is: %d\n", res);

    return 0;
}
