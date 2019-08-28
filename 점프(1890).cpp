#include<stdio.h>
int map[100][100];
long int dp[100][100];

void initializing(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			dp[i][j]=-1;
	}
}

long int find(int i, int j, int n){
	if(i>n||j>n) return 0;
	else if(i==n&&j==n)	return 1;
	else if(dp[i][j] != -1) return dp[i][j];
	else{
		int x = map[i][j];
		if(x==0)
			dp[i][j]=0;
		else
			dp[i][j] = find(i+x, j, n) + find(i,j+x, n);
		return dp[i][j];
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d", &map[i][j]);
	}
	initializing(n);
	printf("%ld", find(0, 0, n-1));
} 
