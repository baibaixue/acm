#include<stdio.h>//ͳ���ַ�a 11��19�� ��ѩ 
int main(){
	char s[10000];
	int i;
	for(i=0;;i++){
		scanf("%c",&s[i]);//�����ַ� 
		if(s[i]=='\n'){
			break;
		}
	}
	int count=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='a'){//ͳ���ַ� 
			count++;//���� 
		}
	}
	printf("%d\n",count);
	return 0;	
}
