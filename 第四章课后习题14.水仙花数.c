//��ѩ��ˮ�ɻ��� 
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int a,b,c,t,count=0;
	for(i=100;i<=999;i++){//��λ��ѭ�� 
		a=i/100;//��λ�� 
		t=i%100;
		b=t/10;//ʮλ�� 
		c=t%10;//��λ�� 
		if(i==pow(a,3)+pow(b,3)+pow(c,3)){
			if(count==0){
				printf("%d",i);
			}
		else{
			printf(" %d",i);
		}//ÿ������֮����һ���ո� 
		count+=1;
		}
	}
	printf("\n");
	return 0;
 } 
