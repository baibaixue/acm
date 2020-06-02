#include<stdio.h>//查找最大元素 
int main(){
	char a[100];
	int i,j;
	int max;
	while(scanf("%s",a)!=EOF){//读入字符串 
		for(j=0;a[j]!='\0';j++);//j为字符串长度 
			max=a[0];//初始化最大值 
			for(i=0;i<j;i++){
				if(a[i]>max){
					max=a[i];//找到最大值 
				}
			}
		for(i=0;i<j;i++){
			printf("%c",a[i]);//依次输出字符串 
			if(a[i]==max){
				printf("(max)");//在最大值的后面添加（max） 
			}
		}
		printf("\n");
	}
	return 0;
}
