#include<stdio.h>//�������Ԫ�� 
int main(){
	char a[100];
	int i,j;
	int max;
	while(scanf("%s",a)!=EOF){//�����ַ��� 
		for(j=0;a[j]!='\0';j++);//jΪ�ַ������� 
			max=a[0];//��ʼ�����ֵ 
			for(i=0;i<j;i++){
				if(a[i]>max){
					max=a[i];//�ҵ����ֵ 
				}
			}
		for(i=0;i<j;i++){
			printf("%c",a[i]);//��������ַ��� 
			if(a[i]==max){
				printf("(max)");//�����ֵ�ĺ�����ӣ�max�� 
			}
		}
		printf("\n");
	}
	return 0;
}
