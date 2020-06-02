#include<stdio.h>
int main(){
	int time;
	int n,m;
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
			int floor=0;
			time=0;
			for(int i=0;i<n;i++){
				scanf("%d",&m);
				for(int i=0;;i++){
					if(m>floor){
						time+=6;
						floor++;	
					}
					if(m<floor){
						time+=4;
						floor--;
					}if(m==floor){
						break;
					}
				}
			time+=5;
		}
			printf("%d\n",time);
		}else 
		break;
	}
	return 0;
} 
