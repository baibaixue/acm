#include<stdio.h>
#include<math.h>
int main(){
	int n,m;
	int a,b,x,max,i,j;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n!=0&&m!=0){
			max=0;
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					scanf("%d",&x);
					if(fabs((double)x)>fabs((double)max)){
						max=x;
						a=i+1;
						b=j+1;
					}
			}
		}
		printf("%d %d %d\n",a,b,max);
	}
	else
	break;
	}
	return 0;
}
