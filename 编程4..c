#include<stdio.h>////11ÔÂ26ºÅ  °×Ñ© Ð¡Ð´×ÖÄ¸×ª´óÐ´×ÖÄ¸ 
void change(char* a){
	int i;
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-32;//½«Ð¡Ð´×ÖÄ¸×ª±äÎª´óÐ´×ÖÄ¸ 
		}
	}
}
int main(){
	char c[1000];
	scanf("%s",c);//¶ÁÈë×Ö·û´® 
	change(c);
	int i;
	for(i=0;c[i]!='\0';i++){
		printf("%c",c[i]);// Êä³ö 
	}
	printf("\n");
	return 0;
}
 
