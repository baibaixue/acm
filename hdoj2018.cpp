#include <stdio.h>
int main(void)
{
	int n, i, a[55];
	while(scanf("%d", &n), n)
	{
		if(n!=0){
			a[1] = 1;
			a[2] = 2;
			a[3] = 3;
			for(i = 4; i <= n; i ++)
			{
				a[i] = a[i-1] + a[i-3];
			}
			printf("%d\n", a[n]);
		}
		else
		break;
	}
	return 0;
}

