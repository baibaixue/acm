#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#define INF 0x3f3f3f
using namespace std;

int n;
struct node{
    long long cure,cost;
    node(long long cu,long long co){
        cure=cu;cost=co;
    }
    bool operator<(const node& rhs)const{
        if(cost==rhs.cost) return cure>rhs.cure;
        return cost<rhs.cost;
    }
};

set<node>s;

int main(){
    int t,kase;
    scanf("%d",&t);
    long long need,cu,co;
    while(t--){
        s.clear();
        long long maxcur=-1;
        scanf("%d",&n);
        for(int k=1;k<=n;k++){
            scanf("%d",&kase);
            if(kase==1){
                scanf("%lld",&need);
                if(need>maxcur){
                    printf("-1\n");
                    continue;
                }
                else{
                    set<node>:: iterator it;
                    for(it=s.begin();it!=s.end();it++){
                        if(it->cure>=need){
                            printf("%lld\n",it->cost);
                            break;
                        }
                    }
                }
            }
            else{
                scanf("%lld%lld",&cu,&co);
                node doc(cu,co);
                s.insert(doc);
                if(cu>maxcur) maxcur=cu;
            }
        }
    }
}
