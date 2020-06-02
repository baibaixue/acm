#include<cstdio>
int main(){
	int n[10];
	for(int i=0;i<10;i++){
		scanf("%d",&n[i]);
	}
	int a;
	scanf("%d",&a);
	int cnt=0;
	for(int i=0;i<10;i++){
		if(n[i]<=a+30){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
