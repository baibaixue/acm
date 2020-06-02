#include<cstdio>
#include<algorithm>
using namespace std;
int x[5];
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&x[0],&x[1],&x[2])!=EOF){
		sort(x,x+3);
		printf("%d->%d->%d\n",x[0],x[1],x[2]);
	}
	return 0;
}
