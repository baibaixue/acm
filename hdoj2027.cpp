#include<stdio.h>
int main(){
	int n,i1,i2,j;
	char a[100];
	int b[5]={0,0,0,0,0};
	while(scanf("%d%*c",&n)!=EOF){
		while(n--){
			gets(a);
			for(j=0;a[j]!='\0';j++);
			for(i2=0;i2<j;i2++){
				if(a[i2]=='a'){
					b[0]++;
				}else if(a[i2]=='e'){
					b[1]++;
				}else if(a[i2]=='i'){
					b[2]++;
				}else if(a[i2]=='o'){
					b[3]++;
				}else if(a[i2]=='u'){
					b[4]++;
				}
			}
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",b[0],b[1],b[2],b[3],b[4]);
			for(i2=0;i2<5;i2++){
				b[i2]=0;
			}
			if(n!=0){
				printf("\n");
			}
		}
		
	}
	return 0;
}
