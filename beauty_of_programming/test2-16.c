// Longest increasing subsequence
// 最长递增子序列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSubsequence(int a[], int start_i[], int i)
{
	if (start_i[i] == -1)
	{
		printf("%d ", a[i]);
		return ;
	}

	printSubsequence(a, start_i, start_i[i]);

	printf("%d ", a[i]);
}

void printArray(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int LIS(int a[], int len)
{
	// using Dynamic programming to solve program
	int *res, *start_i;
	int i, j, max, max_i;

	res = (int *)malloc(len * sizeof(int));
	start_i = (int *)malloc(len * sizeof(int));

	max = res[0] = 1;
	max_i = 0;
	for (i = 0; i < len; i++)
		start_i[i] = -1;

	for (i = 1; i < len; i++)
	{
		
		res[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (a[j] < a[i] && res[i] < res[j] + 1)
			{
				res[i] = res[j] + 1;
				start_i[i] = j;
			}
		}
		if (res[i] > max)
		{
			max = res[i];
			max_i = i;
		}
	}

	printf("the lengh of longest increase subsequence: %d, the subsequece is: ", max);
	//printf("max_i = %d\n", max_i);

	printSubsequence(a, start_i, max_i);
	printf("\n");
	free(res);
	free(start_i);

	return max;
	
}

int LIS2(int a[], int len)
{
	/*
	another method to solve the problem
	link: http://www.slyar.com/blog/longest-ordered-subsequence.html
	link: http://www.felix021.com/blog/read.php?1587
	注意:这里的res数组保存的不一定就是LIS串
	*/

	int *res;
	int i, a_i, res_top;

	res = (int *)malloc(len * sizeof(len));
	res[0] = a[0];
	
	for (a_i = 1, res_top = 0; a_i < len; a_i++)
	{
		if (a[a_i] > res[res_top])
		{
			// push a[a_i] into res[]
			res_top++;
			res[res_top] = a[a_i];
		}
		else
		{
			for (i = 0; i <= res_top; i++)
			{
				if (res[i] > a[a_i])
					break;
			}
			res[i] = a[a_i];
		}
	}

	res_top++;
	printf("the lengh of longest increase subsequence: %d, the subsequece is: ", res_top);
	printArray(res, res_top);
	free(res);

	return res_top;
}

/*
int LIS2b(int a[], int len)
{

	int *res, *LIS;
	int i, a_i, res_top, LIS_top, exchange_ptr; 
	
	res = (int *)malloc(len * sizeof(len));
	LIS = (int *)malloc(len * sizeof(len));
	LIS[0] = res[0] = a[0];
	
	for (a_i = 1, LIS_top = res_top = 0; a_i < len; a_i++)
	{
		exchange_ptr = res_top;
		if (a[a_i] > res[res_top])
		{
			// push a[a_i] into res[]
			res_top++;
			res[res_top] = a[a_i];
		}
		else
		{
			for (i = 0; i <= res_top; i++)
			{
				if (res[i] > a[a_i])
					break;
			}
			res[i] = a[a_i];
			exchange_ptr = i;
		}
		if (res_top > LIS_top)
		{
			LIS_top = 0;
			for (i = 0; i <= res_top; i++)
			{
				LIS[i] = res[i];
				LIS_top++;
			}
			LIS_top--;
		}
	}

	res_top++;
	printf("the lengh of longest increase subsequence: %d, the subsequece is: ", res_top);
	printArray(res, res_top);

	LIS_top++;
	printf("the lengh of longest increase subsequence: %d, the subsequece is: ", LIS_top);
	printArray(LIS, LIS_top);
	free(res);

	return res_top;
}
*/

int main()
{
    //int arr[] = {1,-8,0,-7,4,-5,6,-4,-3,-2};
	int arr[] = {2,1,5,3,6,4,20,21,7,8,9,6};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArray(arr, len);
    LIS(arr, len); 
	LIS2(arr, len);

    return 0;
}
