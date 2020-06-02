#include<cstdio>
#include<algorithm>//sort的头文件 
using namespace std;
const int maxn=10000;
int main(){
	int n,q,x,a[maxn],kase=0;
	while(scanf("%d%d",&n,&q)!=EOF&&n!=0){
		printf("Case# %d:\n",++kase);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);//排序 
		while(q--){
			scanf("%d",&x);
			int p=lower_bound(a,a+n,x)-a;//lower_bound查找大于或者等于x的第一个位置 
			if(a[p]==x){
				printf("%d found at %d\n",x,p+1);
			}else{
				printf("%d not found\n",x);
			}
		}
	}
	return 0;
} 
