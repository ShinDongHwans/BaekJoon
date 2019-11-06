#include<stdio.h>
int main(){
	int n;
	int i, j;
	scanf("%d", &n);
	for(i=1;i<=n;i+=2){
		for(j=0;j<(n-i)/2;j++)
			printf(" ");
		for(j=0;j<i;j++)
			printf("*");
		printf("\n");
	}
}
