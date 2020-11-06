#include<stdio.h>//Ã°ÅİÅÅĞòflag²éÕÒ 11ÔÂ18ÈÕ °×Ñ©
int c[10]={3,6,1,2,5,4,9,14,7,11};
int main(){
	int i,j;
	int flag=0;
	int n,t;
	printf("print your searching number:\n");
	scanf("%d",&n);
	for(i=0;i<10;i++){
		for(j=0;j<9-i;j++){
			if(c[j]==n){
				flag=1;
			}
			if(c[j]>c[j+1]){
				t=c[j];
				c[j]=c[j+1];
				c[j+1]=t;
			}
		}
	}
	if(flag==1){
		printf("%d can be found.\n",n);
	}else{
		printf("%d can not be found\n",n);
	}
	printf("the sort of this group is:\n");
	for(i=0;i<10;i++){
		printf("%d ",c[i]);
	}
	printf("\n");
	return 0;
} 
