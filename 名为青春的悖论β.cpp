#include<cstdio>
#include<string.h>
#define maxn 4500
int s[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(s,0,sizeof(s));
		s[0]=1;
		int k=0;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			k=k+a;
			s[k]=1;
		}
		if(k%2==1){
			printf("0\n");
		}else if(k%2==0){
			int count=0;
			for(int i=0;i<k/2;i++){
				if(s[i]==1){
					for(int j=i+1;j<k/2;j++){
						if(s[j]==1&&s[k/2+i]==1&&s[k/2+j]==1){
							count++;
						} 
					} 
				}
			}
			printf("%d\n",count);
		}
	}
	return 0;
}
