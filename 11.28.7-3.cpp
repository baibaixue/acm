#include<cstdio> 
int main(){
	int h,m;
	while(scanf("%2d:%2d",&h,&m)!=EOF){
		if(h<10){
			if(m<10){
				printf("Only 0%d:0%d.  Too early to Dang.\n",h,m); 
			}else if(m>=10){
				printf("Only 0%d:%d.  Too early to Dang.\n",h,m); 
			}
		}else if(h>=10&&h<=11){
			if(m<10){
				printf("Only %d:0%d.  Too early to Dang.\n",h,m); 
			}else if(m>=10){
				printf("Only %d:%d.  Too early to Dang.\n",h,m); 
			}
		}else if(h==12&&m==0){
			printf("Only 12:00.  Too early to Dang.\n",h,m); 
		}else{
			h-=12;
			if(m>0){
				h+=1;
			}for(int i=0;i<h;i++){
				printf("Dang");
			}
			printf("\n");
		}
	}
		return 0;
}
