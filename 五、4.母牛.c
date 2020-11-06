#include <stdio.h>//母牛数 11月18日 白雪 
int main()
{
	int n, i, a[55];//定义数组 n为第几年 
	while(scanf("%d", &n), n)
	{
		if(n!=0){
			a[1] = 1;
			a[2] = 2;
			a[3] = 3;
			for(i = 4; i <= n; i ++)
			{
				a[i] = a[i-1] + a[i-3];//每四年递归 
			}
			printf("%d\n", a[n]);//输出 
		}
		else
		break;
	}
	return 0;
}

