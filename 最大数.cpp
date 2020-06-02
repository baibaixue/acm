#include<stdio.h>
int main(){
	int x,max=0;
	for(int i=0;;i++){
		scanf("%d",&x);
		if(x==-1){
			break;
		}else{
			if(x>max){
				max=x;
			}
		}
	}
	printf("%d",max);
	return 0;
} 
