#include<cstdio>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int k=1;
		int v;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			if(v<=0){
				k=0;
			}
		}
		if(k==1){
			printf("WeRide.ai\n");
		}else{
			printf("Transform Mobility With Autonomous Driving\n");
		}
	}
}
