/*
给定一个数N，求出1-N之间的数字有多少个1，例如N=11时结果为4（只有1,10,11含1）
若x = abcde，我们来看百位为1出现的次数，这里分3种情况讨论：
1. 百位为0时，假设x = 45021，可以算出百位为1出现情况：
      100~199
     1100~1199
    ...
    44100~44199
    总共是45*100个1
2. 百位为1时，假设x = 45121，可以算出百位为1出现情况：
      100~199
     1100~1199
    ...
    44100~44199
    45100~45145
    总共是45*100+(45+1)个1
3. 百位大于1时，假设x = 45821，可以算出百位为1出现情况：
      100~199
     1100~1199
    ...
    44100~44199
    45100~45199
    总共是(45+1)*100个1

于是，我们可以找到这样一个规律，对于某一特定的位，该位出现1的次数为：
1. 若该位的值为0，则该位出现1的次数=高位值*该位的进制
2. 若该位的值为1，则该位出现1的次数=高位值*该位的进制+低位值+1
3. 若该位的值大于1，则该位出现1的次数=（高位值+1）*该位的进制
*/

#include <stdio.h>

int find_1(int n)
{
    int factor;
    int res;
    int low, cur, high;
    factor = 1;
    res = 0;
    while (n / factor)
    {
        low = n % factor;
        cur = n / factor % 10;
        high = n / factor / 10;
        if (cur == 0)
            res += high * factor;
        else if (cur == 1)
            res += high * factor + low + 1;
        else
            res += (high+1) * factor;
        factor *= 10;
    }

    return res;
}

int main()
{
    int res;
    int n = 19;
    printf("%d contains %ds one.\n", n, find_1(n));
    return 0;
}
