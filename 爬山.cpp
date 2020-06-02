#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long int h[100020];
int main(){
	int t,n,x;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&h[i]);
		}
		sort(h,h+n);
		long long int min=h[1]-h[0];
		long long int count=1;
		int b=1;
		int k=1;
		for(int i=1;i<n-1;i++){
			if(min>(h[i+1]-h[i])){
				min=(h[i+1]-h[i]);
				count=1;
			}else if(min==(h[i+1]-h[i])){
				if(min==0){
					if((h[i-1]-h[i+1])==min){
						b++;
					}else{
						b=1;
					}
				}
				count+=b;
			}
		}
		printf("%d %d\n",min,count);
	}
	return 0;
}
