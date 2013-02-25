/*
* top-k problem
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, k, result, count;
    int i, j, temp;
    int *arr = (int*)malloc(1000*sizeof(int));

    while (scanf("%d", &num) != EOF)
    {
        count = 1;
        for (i=0; i<num; i++)
            scanf("%d", arr+i);

        scanf("%d", &k);
        for (i=0; i<num-1; i++)
        {
            for (j=num-1; j-1>i; j--)
            {
                if (arr[j-1] > arr[j])
                {
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }
            //printf("a[%d]=%d\n", i, arr[i]);
            if ( i>0 && arr[i-1]!=arr[i] )
                count++;

            if (count == k)
            {
                printf("%d\n", arr[i]);
            }
        }
    }
}
