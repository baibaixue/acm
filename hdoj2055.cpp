#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			char x;
			int y;
			scanf("%*c%c",&x);
			scanf("%d",&y);
			if(x>='A'&&x<='Z'){
				y=y+(int)(x-'A'+1);
			}else if(x>='a'&&y<='z'){
				y=y-(int)(x-'a'+1);
			}
			printf("%d\n",y);
		}
	}
	return 0;
}
