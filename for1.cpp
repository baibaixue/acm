#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i=1;
	int count=1;
	
	//for(count=1;count<=n;count++){
		//i*=count;
	//}
	
	for (count=n;count>1;count--){
		i*=count;
	}
	printf("%d!=%d",n,i);
	return 0;
}
