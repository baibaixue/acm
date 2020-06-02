#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 200000
using namespace std;
struct node{
    int l,r;
    int f;
    int lroom,rroom,mroom;
}tree[maxn];
void build(int s,int t,int k){
    tree[k].l=s;
    tree[k].r=t;
    tree[k].f=-1;
    tree[k].lroom=tree[k].rroom=tree[k].mroom=t-s+1;
    if(s==t){
    	return;
	}
	int m=(s+t)/2;
    if(s<=m){
    	build(s,m,k*2);	
	}
    if(t>m){
    	build(m+1,t,k*2+1);
	}
}
void pushDown(int k){
    if(tree[k].f==-1){
		return;
	}
    tree[k*2].f=tree[k*2+1].f=tree[k].f;
    if(tree[k].f==1){
        tree[k*2].lroom=tree[k*2].rroom=tree[k*2].mroom=0;
        tree[k*2+1].lroom=tree[k*2+1].rroom=tree[k*2+1].mroom=0;
    }
    else{
        tree[k*2].lroom=tree[k*2].rroom=tree[k*2].mroom=tree[k*2].r-tree[k*2].l+1;
        tree[k*2+1].lroom=tree[k*2+1].rroom=tree[k*2+1].mroom=tree[k*2+1].r-tree[k*2+1].l+1;
    }
    tree[k].f=-1;
}
void pushUp(int k){
    tree[k].lroom=tree[k*2].lroom;
    tree[k].rroom=tree[k*2+1].rroom;
    if(tree[k].lroom==tree[k*2].r-tree[k*2].l+1){
        tree[k].lroom+=tree[k*2+1].lroom;
    }
    if(tree[k].rroom==tree[k*2+1].r-tree[k*2+1].l+1){
    	tree[k].rroom+=tree[k*2].rroom;
	}
    tree[k].mroom=max(tree[k*2].mroom,tree[k*2+1].mroom);
    tree[k].mroom=max(tree[k].mroom,tree[k*2].rroom+tree[k*2+1].lroom);
}
 
void update(int s,int t,int k,int f){
    if(tree[k].l>=s&&tree[k].r<=t){
        tree[k].f=f;
        if(f==1){
            tree[k].lroom=tree[k].rroom=tree[k].mroom=0;
        }
        else{
            tree[k].lroom=tree[k].rroom=tree[k].mroom=tree[k].r-tree[k].l+1;
        }
        return ;
    }
    pushDown(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(s<=m){
    	update(s,t,k*2,f);
	}
    if(m<t){
    	update(s,t,k*2+1,f);
	}
    pushUp(k);
}
 
int query(int k,int w){
    if(tree[k].l==tree[k].r){
    	return tree[k].l;
	}
    pushDown(k);
    if(tree[k*2].mroom>=w){
    	return query(k*2,w);
	}
    else if(tree[k*2].rroom+tree[k*2+1].lroom>=w){
        return tree[k*2].r-tree[k*2].rroom+1;
    }
    return query(k*2+1,w);
}
 
 
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
    	build(1,n,1);
	    while(m--){
	        int c,a,b;
	        scanf("%d",&c);
	        if(c==1){
	            scanf("%d",&a);
	            if(tree[1].mroom<a){
	            	printf("0\n");
				}
	            else{
	                int ans=query(1,a);
	                printf("%d\n",ans);
	                update(ans,ans+a-1,1,1);
	            }
	        }
	        else{
	            scanf("%d%d",&a,&b);
	            update(a,a+b-1,1,0);
	        }
    	}
	}
    return 0;
}
