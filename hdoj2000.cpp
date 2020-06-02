#include<stdio.h>
#include<string.h> 
int main()
{
	char a[3];
	int i,j;
	char t;
	while(scanf("%c%c%c\n",&a[0],&a[1],&a[2])!=EOF){
		for(i=0;i<3;i++){
			for(j=i+1;j<3;j++){
				if(a[i]>a[j]){
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		printf("%c %c %c\n",a[0],a[1],a[2]);
}
	return 0;
 }
