#include<cstdio> 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int j=0,o=0;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			if(a%2==0){
				o++;
			}else{
				j++;
			}
		}
		printf("%d %d\n",j,o);
	}
	return 0;
}
