/*
��Ŀ��
����һ��������N����N�Ľ׳˵�ĩβ�м���0��
��N=10ʱ��N!=3628800��ĩβ����0
http://t.jobdu.com/thread-98709-1-1.html

������
���Խ�����ת������1-N������5���ֵĴ���
*/
#include <stdio.h>

int find1(int n)
{
    int i;
    int count = 0;
    for (; n > 0; n--)
    {
        i = n;
        while (i > 0 && (i % 5 == 0))
        {
            count++;
            i /= 5;
        }
    }
    return count;
}

int find2(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int main()
{
    int n = 30;
    printf("algo1: %d! contains %d zeros\n", n, find1(n));
    printf("algo2: %d! contains %d zeros\n", n, find2(n));
    return 0;
}
