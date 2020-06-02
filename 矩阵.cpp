#include<stdio.h>
int s[1020][1020];
int main(){
	int n,m,k,t;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d%d%d",&n,&m,&k);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					scanf("%d",&s[i][j]);
				}
			}
			int c;
			for(int i=0;i<=n-k;i++){
				c=1;
				for(int j=i;j<i+k;j++){
					for(int o=i;o<i+j;o++){
						if(s[j][o]==1){
							c=0;
							break;
						}
					}
				}
				if(c==1){
					break;
				}
			}
			if(c==1) {
			printf("Yes\n");
			break;}
			
			else {
			printf("No\n");
			break;
		}
		}
	}
	return 0;
}
