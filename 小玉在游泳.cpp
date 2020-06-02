#include<cstdio>
int main(){
	double x;
	scanf("%lf",&x);
	double sum=2.0;
	double last=2.0;
	int steps=1;
	for(int i=1;;i++){
		if(sum>=x){
			break;
		}
		last=last*0.98;
		sum+=last;
		steps++;	
	}
	printf("%d\n",steps);
	return 0;
}
