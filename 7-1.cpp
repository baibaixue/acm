#include<cstdio>
#include<algorithm>
#define maxn 100+10
long long int commen(long long int a,long long int b){
	int i;
	if(a>b){
		long long int t=a;a=b;b=t;
	} 
	long long int r;
	while(a){
		r=b%a;
		b=a;
		a=r;
	}
	return b; 
}
long long int gbs(long long int a,long long int b){
	if(commen(a,b)!=-1){
		return a*b/commen(a,b);
	}else
	return a*b;
}
long long int a[maxn],b[maxn];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
			for(int i=0;i<n;i++){
				scanf("%lld/%lld",&a[i],&b[i]);
			}
			long long int c=b[0];
			long long int x=0;
			for(int i=1;i<n;i++){
				c=gbs(c,b[i]);
				a[i-1]=a[i-1]*(c/b[i-1]);
				a[i]=a[i]*(c/b[i]);
				a[i]+=a[i-1];
				b[i]=c;
				x+=a[i]/b[i];
				a[i]=a[i]%b[i];
				int k=0;
				if(a[i]<0){
					a[i]=-a[i];
					k=1;
				}
				if(a[i]>0){
					for(;;){
						if(commen(a[i],b[i])!=-1&&commen(a[i],b[i])!=1){
							int f=commen(a[i],b[i]);
							a[i]=a[i]/f;
							b[i]=b[i]/f;
						}else{
							break;
						}
					}
				}
				if(k==1){
					a[i]=-a[i];
				}
				c=b[i];
			}
				if(a[n-1]==0){
					printf("%lld",x);
				}
				else if(x==0){
						printf("%lld/%lld",a[n-1],b[n-1]);
					}
				else{
					printf("%lld %lld/%lld",x,a[n-1],b[n-1]);
				}
//			for(int i=1;i<n;i++){
//				c=gbs(c,b[i]);
//			}int sum=0;
//			for(int i=0;i<n;i++){
//				a[i]=a[i]*(c/b[i]);
//				sum+=a[i];
//			}
//			long long int x,y;
//			x=sum/c;
//			y=sum%c;
//			if(y==0){
//				printf("%lld",x);
//			}
//			else{
//				for(;;){
//					if(commen(y,c)!=-1&&commen(y,c)!=1){
//						int f=commen(y,c);
//						y=y/f;
//						c=c/f;
//					}else{
//						break;
//					}
//				}
//				if(x==0){
//					printf("%lld/%lld",y,c);
//				}else{
//					printf("%lld %lld/%lld",x,y,c);
//				}
//			}
			printf("\n");
		}
	}
	return 0;
} 
