#include <stdio.h>

int main()
{
	int x,count=0;
	double sum=0;
	scanf("%d",&x);
	int number[100]; 
	while(x!=-1){
		number[count]=x;
		sum+=x;
		count++;
		scanf("%d",&x);
	}
	printf("平均数为%f\n",1.0*sum/count);
	
	if (count>0){
		int i;
		double average=sum/count;
		for (i=0;i<count;i++){
				if (number[i]>average){
				printf("%d\n",number[i]);
			}
		}
	}
	return 0;
}
