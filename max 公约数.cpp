#include <stdio.h>

int main(){
	int a,b;
	printf("����������������");
	scanf("%d %d",&a,&b);
	int i;
	for(i=a;i>0;i--){
		if(a%i==0&&b%i==0){
			break;	
		}	
	} 
	printf("%d��%d�����Լ����%d��",a,b,i);
	return 0;
}
