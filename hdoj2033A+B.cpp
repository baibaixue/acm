#include<stdio.h>
int main(){
	int c[10];
	int h,m,s;
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			for(int i=0;i<6;i++){
				scanf("%d",&c[i]);
			}
			h=c[0]+c[3];
			m=c[1]+c[4];
			s=c[2]+c[5];
			if(s>=60){
				s=s%60;
				m++;
			}if(m>=60){
				m=m%60;
				h++;
			}
			printf("%d %d %d\n",h,m,s);
		}
	}
	return 0;
}
