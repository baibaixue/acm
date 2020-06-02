#include<stdio.h>
#include<string.h>
#define maxn 105 
int less(char* s,int p,int q){
	int n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[(p+i)%n]!=s[(q+i)%n])
			return s[(p+i)%n]<s[(q+i)%n];
}
int main(){
	int t;
	char s[maxn];
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int ans=0;
		int n=strlen(s);
		for(int i=1;i<n;i++)
			if(less(s,i,ans))
				ans=i;//ans为序列的第一位在数组中对应的值 
		for(int i=0;i<n;i++)
			putchar(s[(i+ans)%n]);
		putchar('\n');	
		} 
	return 0;
} 
