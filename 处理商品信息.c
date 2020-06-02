#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct book{ 
	double p; 
	char s[100]; 
}B[100];
int cmp( const void *a ,const void *b) { 
	return (*(struct book*)a).p> (*(struct book*)b).p? 1 : -1; 
} 
int main(){
	int i=0;
	while(scanf("%s",B[i].s)!=EOF){
		scanf("%lf",&B[i].p);
		i++;
		getchar();
	}
	qsort(B,i,sizeof(B[0]),cmp);
	int j;
	for(j=0;j<i;j++){
		printf("%s %.2f\n",B[j].s,B[j].p);
	}
	return 0;
} 
