#include <stdio.h>

int main()
{
	int x;
	//scanf("%d",&x);
	int count=0;
	for(x=2;count<50;x++){
		int i;
		int a=1; 
		for(i=2;i<x;i++){
			if(x%i==0){
				a=0;
				break;
			}
		} 
		if(a==1){
			printf("%d ",x);
			count++;
		}
		//else{
			//printf("%d²»ÊÇËØÊý¡£",x);
		//}
	}
	return 0;

}
