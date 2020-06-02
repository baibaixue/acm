#include<cstdio> 
#define maxn 110
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int n;
		scanf("%d",&n);
		int a1[maxn]={0},a2[maxn]={0},b1[maxn]={0},b2[maxn]={0};
		int aa=0,bb=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&a1[i],&a2[i],&b1[i],&b2[i]);
		}
		for(int i=0;i<n;i++){
			if(a2[i]==(a1[i]+b1[i])&&b2[i]==(a1[i]+b1[i])){
				continue;
			}
			if(a2[i]==(a1[i]+b1[i])){
					a--;
					aa++;
				if(a<0){
					printf("A\n%d\n",bb);
					break;
				}
			}if(b2[i]==(a1[i]+b1[i])){
				b--;
				bb++;
				if(b<0){
					printf("B\n%d\n",aa);
					break;
				}
			}
		}
	}
	return 0;
}
