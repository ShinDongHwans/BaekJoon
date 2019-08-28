#include<stdio.h>
int n, m;
int map[100][100];
long int dp[100][100];

void initializing(int n, int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			dp[i][j]=-1;
	}
}

long int find(int i, int j){
	if(i==n-1&&j==m-1)	return 1;
	else if(dp[i][j] != -1) return dp[i][j];
	else{
		if(i!=n-1 && map[i][j]>map[i+1][j]) dp[i][j]+=find(i+1,j); 
		if(i!=0 && map[i][j]>map[i-1][j]) dp[i][j]+=find(i-1,j); 
		if(j!=m-1 && map[i][j]>map[i][j+1]) dp[i][j]+=find(i,j+1); 
		if(j!=0 && map[i][j]>map[i][j-1]) dp[i][j]+=find(i,j-1); 
		return ++dp[i][j];
	}
}

int main(){
	scanf("%d %d", &n, &m);
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			scanf("%d", &map[i][j]);
	}
	initializing(n, m);
	printf("%ld", find(0, 0));
} 
