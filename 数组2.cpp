#include <stdio.h>

int main()
{
	int i;
	printf("������һϵ������\n");
	int count[10];//�������� 
	for (i=0;i<10;i++){
		count[i]=0;          //��ʼ������ ** 
	}
	scanf("%d",&i);
	
	while(i>=0&&i<=9){
		count[i]++;
		scanf("%d",&i);
	}
	if(i=-1){
		for(i=0;i<10;i++){
			printf("%d:%d\n",i,count[i]);
		}
		return 0;
	}
}
