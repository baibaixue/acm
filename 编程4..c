#include<stdio.h>////11��26��  ��ѩ Сд��ĸת��д��ĸ 
void change(char* a){
	int i;
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-32;//��Сд��ĸת��Ϊ��д��ĸ 
		}
	}
}
int main(){
	char c[1000];
	scanf("%s",c);//�����ַ��� 
	change(c);
	int i;
	for(i=0;c[i]!='\0';i++){
		printf("%c",c[i]);// ��� 
	}
	printf("\n");
	return 0;
}
 
