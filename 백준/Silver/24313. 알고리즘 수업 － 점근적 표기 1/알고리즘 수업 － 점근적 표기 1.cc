#include <stdio.h>
int a,b,c,n;
int main(){
	scanf("%d %d %d %d",&a,&b,&c,&n),printf("%d",a<=c && a*n+b<=c*n);
}