#include <stdio.h>
int search(int key,int a[],int length);

int main(void)
{
	int a[]={1,2,3,4,5,77,47,34,22,67,99,76,5,45,3,7,8,6,5};
	int key;
	int result;
	int length=sizeof(a)/sizeof(a[0]);
	printf("请输入一个整数：");
	scanf("%d",&key);
	result=search(key,a,length);
	if(result!=-1){
		printf("%d在第%d个位置上\n",key,result);
	}	 else{
		printf("%d不存在\n",key);
	}
	return 0;
}
	//for (i=0;i<sizeof(a)/sizeof(a[0]);i++){
		//printf("%d   ",a[i]);
	//}
	int search(int key,int a[],int length){
		int result=-1;
		int i;
		for(i=0;i<length;i++){
			if (a[i]==key){
			result=i;
			break;
			}
		}
		return result;
	}
	

 
