#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 502
using namespace std;
int a[maxn],b[maxn],c[maxn];
int sum[maxn*maxn];
int bsearch(int n,int x){
	int l=0,r=n-1;
	int m;
	while(r>=l){
		m=(l+r)/2;
		if(sum[m]==x){
			return 1;
		}if(sum[m]<x){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return -1;
}
int main(){
	int l,n,m;
	int kase=0;
	while(scanf("%d%d%d",&l,&n,&m)!=EOF){
		for(int i=0;i<l;i++){
			scanf("%d",&a[i]);
		}for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}for(int i=0;i<m;i++){
			scanf("%d",&c[i]);
		} 
		sort(a,a+l);
		//sort(b,b+n);
		//sort(c,c+m);
		int s;
		scanf("%d",&s);
		printf("Case %d:\n",++kase);
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				sum[num++]=b[i]+c[j];
			}
		}
		sort(sum,sum+num);
//		for(int i=0;i<num&&i<l;i++){
//			sum[i]+=a[i];
//		}
		while(s--){
			int X;
			scanf("%d",&X);
//			if(a[0]+sum[0]>X||a[l-1]+sum[num-1]<X){
//				printf("NO\n");
//			}else{
				int k=0;
				for(int i=0;i<l;i++){
					int cha=X-a[i];
					if(bsearch(num,cha)==1){
						printf("YES\n");
						k=1;
						break;
					}
				}
				if(k==0){
					printf("NO\n");
				}
			//}

		}
	}
	return 0;
}
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cctype>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//#define N 510
//#define INF 0x3f3f3f3f
//typedef long long LL;
//
//int a[N], b[N], c[N], sum[N*N];
//
//int Search(int num, int n)
//{
//    int l, r, mid;
//    l=0;
//    r=n-1;
//
//    while(l<=r)
//    {
//        mid=(l+r)/2;
//        if(sum[mid]>num)
//            r=mid-1;
//        else if(sum[mid]<num)
//            l=mid+1;
//        else
//            return 1;
//    }
//    return 0;
//}
//
//int main()
//{
//    int l, n, m, k, s, x, cnt=1;
//
//    while(~scanf("%d%d%d", &l, &n, &m))
//    {
//        for(int i=0; i<l; i++)
//            scanf("%d", &a[i]);
//        for(int i=0; i<n; i++)
//            scanf("%d", &b[i]);
//        for(int i=0; i<m; i++)
//            scanf("%d", &c[i]);
//        k=0;
//        for(int i=0; i<l; i++)
//        for(int j=0; j<n; j++)
//        sum[k++]=a[i]+b[j];
//
//        sort(sum, sum+k);
//
//        scanf("%d", &s);
//        printf("Case %d:\n", cnt++);
//
//        while(s--)
//        {
//            int f=0;
//            scanf("%d", &x);
//            for(int i=0; i<m&&!f; i++)
//            {
//                int num=x-c[i];
//                if(Search(num, k))
//                    f=1;
//            }
//            if(f)
//                printf("YES\n");
//            else
//                printf("NO\n");
//        }
//    }
//    return 0;
//}
// 

