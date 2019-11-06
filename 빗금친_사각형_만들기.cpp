#include<stdio.h>
int main(){
	char lectangle[10000]={};
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1;i<=n;i++)
		lectangle[i] = '*';
		
	for(i=n+1; i<=n*(n-1); i+=n){
		lectangle[i] = '*';
		lectangle[i+n-1] = '*';
	}
	
	for(i= n+2; i<=n*(n-1); i+=k)
		lectangle[i] = '*';
		
	for(i=n*(n-1)+1;i<=n*n+1;i++)
		lectangle[i] = '*';
		
	for(i=1; i<=n*n ; i+=n){
		for(j=0 ; j<n ; j++){
			printf("%c", lectangle[i+j]);
		}
		printf("\n");
	}
}
