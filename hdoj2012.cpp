#include<stdio.h>
int  is_prime(int i)
{	int k;
	int a=1; 
	for(k=2;k<i;k++){
		if(i%k==0){
			a=0;
			break;
		}
	}
	return a;
}



int main(){
	int x,y,i,n;
	while(scanf("%d%d",&x,&y)!=EOF){
		int m=1;
		if(x!=0||y!=0){
			for(i=x;i<=y;i++){
				n=i*i+i+41;
				if(is_prime(n)==0){
					m=0;
					break;
				}
			}
			if(m==1){
				printf("OK\n");
			}
			if(m==0){
				printf("Sorry\n");
			}
		}
		else
		break;
	}
	return 0;
}
