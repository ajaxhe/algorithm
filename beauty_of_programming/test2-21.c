// 求连续自然数（两个以上）之和
// 2+3+4=9;
#include <stdio.h>
void find(int n)
{
    int k, k2, i, m, count;
    count = 0;
    for (k = n / 2 + 1; k >= 2; k--)
    {
        if (k % 2)
        {
            // k为奇数
            k2 = k / 2;
            // 判断k是否能被n整除
            if (n % k)
                continue;
            m = n / k;
            if (m - k2 < 1)
                continue;
            i = -k2;
        }
        else
        {
            // k为偶数
            k2 = k / 2;
            m = (n / k2 - 1) / 2;
            // 检查(2m+1)*(k/2)=n?
            if ( (m*2+1)*k2 != n)
                continue;
            if (m - k2 < 0)
                continue;
            i = -(k2-1);
        }
        count++;
        printf("k=%d\n", k);
        printf("    ");
        for (; i < k2; i++)
            printf("%d+", m + i);
        printf("%d\n", m + i);
    }
    printf("total sum: %d\n", count);
}

int main()
{
    find(694575);
    return 0;
}
