#include <stdio.h>
int main(){int n, k, r, c, i, j, t;int a[1000];while (scanf("%d", &n) != EOF){c = 1;for (i=0; i<n; i++)scanf("%d", a+i);scanf("%d", &k);for (i=0; i<n; i++){for (j=n-1; j-1>=i; j--){if (a[j-1] > a[j]){t = a[j-1];a[j-1] = a[j];a[j] = t;}}if ( i>0 && a[i-1]!=a[i] )c++;if (c == k){printf("%d\n", a[i]);break;}}}}
