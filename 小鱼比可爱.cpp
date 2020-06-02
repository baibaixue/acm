#include<cstdio>
int main(){
	int num[105];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=i;j>=0;j--){
			if(num[j]<num[i]){
				cnt++;
			}
		}
		printf("%d",cnt);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
