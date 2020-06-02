#include<stdio.h>
int is_month(int m,int y);
int is_year(int y);
int main(){
	int y,m,d;
	while(scanf("%d/%d/%d",&y,&m,&d)!=EOF){
		d=d+is_month(m,y);
		printf("%d\n",d);
	}
	return 0;
}
int is_year(int y){
	if((y%4==0&&y%100!=0)||y%400==0){
		return 1;
	}
	else{
		return 0;
	}
}
int is_month(int m,int y){
	int a[]={0,31,61,92,123,153,183,214,245,275,306,336};
	int sum;
	sum=a[m-1];
	if(m>2){
		if(is_year(y)){
			sum-=1;
		}else{
			sum-=2;
		}
		
	}
	return sum;
} 

