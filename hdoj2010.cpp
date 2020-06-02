#include<stdio.h>
#include<math.h>
int main()
{
	int m,n;
	int i;
	int a,b,c,t;
	int x=0,count=0;
	while(scanf("%d %d",&m,&n)!=EOF){
		x=0,count=0;
	for(i=m;i<=n;i++){
		a=i/100;
		t=i%100;
		b=t/10;
		c=t%10;
		if(i==pow((double)a,3.0)+pow((double)b,3.0)+pow((double)c,3.0)){
			if(count==0){
			printf("%d",i);
		}else{
			printf(" %d",i);
		}
		count+=1;
		}else{
			x+=1;
		}
	}
	if(x==n-m+1){
		printf("no");
	}
	printf("\n");
	}
	return 0;
 } 
