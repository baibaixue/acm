#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 100
int Adam[maxn];
int A[maxn];
int E[maxn];
int Eve[maxn];
int link[maxn][maxn];
int n;
int find(int x){
	for(int i=1;i<=n;i++){
		if(link[x][i]==1&&A[i]==0){
			A[i]=1;
			if(E[i]==0||find(E[i])){
				E[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int SUM(){
	int sum=0;
	for(int i=1;i<=n;i++){
		memset(A,0,sizeof(A));
		if(find(i)){				
			sum++;
		}
	}
	return sum;
}
int num(char c1,char c2){
	int m=0;
	if(c1=='A'){
		m+=140;
	}else if(c1=='2'){
		m+=20;
	}else if(c1=='3'){
		m+=30;
	}else if(c1=='4'){
		m+=40;
	}else if(c1=='5'){
		m+=50;
	}else if(c1=='6'){
		m+=60;
	}else if(c1=='7'){
		m+=70;
	}else if(c1=='8'){
		m+=80;
	}else if(c1=='9'){
		m+=90;
	}else if(c1=='T'){
		m+=100;
	}else if(c1=='J'){
		m+=110;
	}else if(c1=='Q'){
		m+=120;
	}else if(c1=='K'){
		m+=130;
	}
	if(c2=='H'){
		m+=4;
	}else if(c2=='S'){
		m+=3;
	}else if(c2=='D'){
		m+=2;
	}else if(c2=='C'){
		m+=1;
	}
	return m;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(A,0,sizeof(A));
		memset(E,0,sizeof(E));
		memset(Adam,0,sizeof(Adam));
		memset(Eve,0,sizeof(Eve));
		memset(link,0,sizeof(link));
		for(int i=1;i<=n;i++){
			char c1,c2;
			getchar();
			scanf("%c%c",&c1,&c2);
			Adam[i]=num(c1,c2);
		}
		for(int i=1;i<=n;i++){
			char c1,c2;
			getchar();
			scanf("%c%c",&c1,&c2);
			Eve[i]=num(c1,c2);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(Eve[j]>Adam[i]){
					link[j][i]=1;
				}
			}
		}
		printf("%d\n",SUM());
	}
	return 0;
} 

