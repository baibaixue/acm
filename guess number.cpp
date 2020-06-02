#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(0));
	int number=rand()%100+1;
	int count=1;
	int a;
	printf("我已想好一个100以内的整数。快来猜吧！\n");
	scanf("%d",&a);
	while (a!=number){
		if (a>number){
			printf("您猜的数大了。\n");
		}
		else{
			printf("您猜的数小了。\n");
		}
		count++;
		scanf("%d",&a);
	}
	printf("恭喜您猜到这个数，这个数就是%d，您共猜了%d次。\n",number,count);
	return 0;
}
