// write by xiaojun
#include <iostream>
#include <cstdio>

using namespace std;

const int NUM = 1000002;

int main()
{
	int n,result,index,elem1,elem2;
	int *a = new int[NUM];

	while(scanf("%d",&n)!=EOF)
	{
		for (int i = 0;i < n;++i)
			scanf("%d",&a[i]);

		result = a[0];
		for (int i = 1;i < n;++i)
			result ^= a[i];

		index = 1 << 30;
		for(;index > 0;index >>= 1)
			if (result & index)
				break;

		elem1 = elem2 = 0;//两组中元素的数目
		for (int i = 0;i < n;++i)
		{
			if (a[i] & index)
				elem1 ^= a[i];
			else
				elem2 ^= a[i];
		}

		printf("%d %d\n",elem2,elem1);
	}

	delete[] a;

	return 0;
}
