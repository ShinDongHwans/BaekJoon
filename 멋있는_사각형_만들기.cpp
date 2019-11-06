#include<stdio.h>
int main(){
	int n;
	int i, j;
	scanf("%d", &n);
	if(n == 3){
		printf("***\n***\n***");
		return 0;
	}
	for(i=0;i<n;i++)
		printf("*");
	printf("\n");
	
	for(i=0;i<(n-2)/2;i++){
		printf("*");
		for(j=0;j<i;j++)
			printf(" ");
		printf("*");
		for(j=0;j<(n-4-2*i)/2;j++)
			printf(" ");
		printf("*");
		for(j=0;j<(n-4-2*i)/2;j++)
			printf(" ");
		printf("*");
		for(j=0;j<i;j++)
			printf(" ");
		printf("*\n");				
	}
	
	for(i=0;i<n;i++)
		printf("*");
	printf("\n");

for(i=(n-2)/2-1;i>=0;i--){
		printf("*");
		for(j=0;j<i;j++)
			printf(" ");
		printf("*");
		for(j=0;j<(n-4-2*i)/2;j++)
			printf(" ");
		printf("*");
		for(j=0;j<(n-4-2*i)/2;j++)
			printf(" ");
		printf("*");
		for(j=0;j<i;j++)
			printf(" ");
		printf("*\n");				
	}
	
	for(i=0;i<n;i++)
		printf("*");
}
