#include<cstdio>
int main(){
	int n;
	int num[105];
	int len=0;
	for(int i=0;;i++){
		scanf("%d",&n);
		if(n!=0){
			num[len++]=n;
		}else{
			break;
		}
	}
	for(int i=len-1;i>0;i--){
		printf("%d ",num[i]);
	}
	printf("%d\n",num[0]);
	return 0;
}
