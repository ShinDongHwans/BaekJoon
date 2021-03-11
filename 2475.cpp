#include<stdio.h>
int main(){
	int i,n,m=0;
	for(i=0;i<5;i++){
		scanf("%d",&n);
		m+=n*n;
	}
	printf("%d",m%10);
}
