//��ѩ����ί���
#include<stdio.h> 
int main(){
	int i,j;
	int a[10];
	for(i=0;i<10;i++){//������������10����ί�Ĵ�� 
		scanf("%d",&a[i]);
	}
	int t;
	for(i=0;i<10;i++){//ð�����򷨽��������� 
		for(j=1;j<9;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	int sum=0;
	for(i=1;i<9;i++){//ȥ�����ֵ����Сֵ�ķ����� 
		sum+=a[i];
	}
	printf("%.2f\n",sum/8.0);//���ƽ���� 
	return 0;
}
