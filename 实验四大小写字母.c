//10��29�գ���ѩ������ѭ��������Сд��ĸ
#include<stdio.h>
int main(){
	char c='A';
	char t='a';
	int i;
	for(i=0;i<26;i++){//��һ��ѭ�� 
		printf("%c ",c++); 
	}
	printf("\n");
	while(t<='z'){//�ڶ���ѭ�� 
		printf("%c ",t++);
	}
	printf("\n");
	return 0;
} 
