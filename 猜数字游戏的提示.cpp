#include<stdio.h>
int main(){
	freopen("guss_number_input.txt","r",stdin);
	freopen("guss_number_output.txt","w",stdout);
	int a[1000],b[1000];
	int n;
	int count=1;
	while(scanf("%d",&n)!=EOF&&n!=0){
		printf("Game %d:\n",count);
		count++;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(;;){
			int A=0,B=0;
			for(int i=0;i<n;i++){
				scanf("%d",&b[i]);
				if(a[i]==b[i]){
					A++;
				}
			}
			if(b[0]==0) break;
			for(int m=1;m<10;m++){
				int c1=0,c2=0;
				for (int i=0;i<n;i++){
					if(a[i]==m) c1++;
					if(b[i]==m) c2++;
				}
				B+=c1>c2?c2:c1;
			}
			printf("	(%d,%d)\n",A,B-A);
		}
	}
	return 0;
}
