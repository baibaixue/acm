#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
#include<functional>
#define INF 0x3f3f3f
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef long long ll;

int n;
struct node{
    int cure,cost;
    node(pair<int,int>p){
        cure=p.first;cost=p.second;
    }
};

struct cmp{
    bool operator()(const node& a,const node& b){
        if(a.cost==b.cost) return a.cure<b.cure;
        return a.cost<b.cost;
    }
};

set<node>s;

int main(){
    int t,kase;
    scanf("%d",&t);
    int need,cu,co;
    while(t--){
        int maxcur=-1;
        scanf("%d",&n);
        for(int k=1;k<=n;k++){
            scanf("%d",&kase);
            if(kase==1){
                scanf("%d",&need);
                set<node>:: iterator it;
                for(it=s.begin();it!=s.end();it++){
                    printf("(%d,%d)\n",it->cure,it->cure);
                }
                if(need>maxcur){
                    printf("-1\n");
                    continue;
                }
                else{
                    set<node>:: iterator it;
                    for(it=s.begin();it!=s.end();it++){
//                        printf("%d\n",it->second);
                        if(it->cure>=need){
                            printf("%d\n",it->cost);
                            break;
                        }
                    }
                }
            }
            else{
                scanf("%d%d",&cu,&co);
                s.insert(node(pair<int,int>(cu,co)));
                if(cu>maxcur) maxcur=cu;
            }
        }
    }
}

