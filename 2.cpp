#include<stdio.h>//打怪兽//2018新生杯 
#define max 100020
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		long long int x[max];
		scanf("%d",&x[0]);
		for(int i=1;i<n;i++){
			scanf("%lld",&x[i]);
			x[i]=x[i]+x[i-1];
		}
		long long int c;
		while(m--){
			scanf("%lld",&c);
			if(x[n-1]<c){
				printf("%d\n",n);
				}
			else{
				int a=0,b=n-1;
				while(a<b){//二分法 
					v=a+(b-a)/2;
					if(x[v]==c){
						printf("%d\n",v);
						break;
					}
					else if(x[v]>c){
						b=v;
					}
					else{
						a=v+1;
					}
					//v+1=lower_bound(x,x+n,c)-x-1//在x数组的第一个位置到第n个位置二分法找
					// 第一个大于c的数并返回该数的地址， 
					//不存在返回最后一个数的地址返回的地址减去起始地址为该数下标 
					if(x[v]<c&&x[v+1]>=c){
						printf("%d\n",v+1);
						break;
					}
				}
			}
		}
	}
	return 0;
}
