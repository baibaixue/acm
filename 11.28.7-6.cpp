#include<cstdio>
#include <string.h>
int id[100000];
int main()
{
    int n,m,i,j=0,x;
    while(scanf("%d",&n)!=EOF){
	    memset(id,0,sizeof(id));
	    while(n--){
	        scanf("%d",&m);
	        if(m>1){
	            for(i=0;i<m;i++){
	                scanf("%d",&x);
	                id[x]++;
	            }
	        }
	        else
	            scanf("%*d");
	    }
	    scanf("%d",&m);
	    while(m--){
	        scanf("%d", &x);
	        if(id[x]==0){
	            if(j==0){
	                printf("%05d",x);
	                id[x]++;
	                j++;
	            }
	            else{
	                printf(" %05d",x);
	                id[x]++;
	            }
	        }
	    }
	    if(j==0)
	        printf("No one is handsome");
	    printf("\n");
	}
    return 0;
}

