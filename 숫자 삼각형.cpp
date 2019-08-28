#include<stdio.h>

int value[1000][1000] = {{0,},};
int sum[1000][1000] = {{0,},};

int max(int i, int j){
	if(j==0)
		return sum[i-1][0];
	else{
		int x = sum[i-1][j];
		int y = sum[i-1][j-1];
		return x>y?x:y;
	}
}

int downStair(int n){
	if(n==1) return value[0][0];
	else{
		sum[0][0] = value[0][0];
		int output=0;
		int i=1;
		for(i;i<n;i++){
			int j=0;
			for(;j<=i;j++)
				sum[i][j]=value[i][j]+max(i,j);
		}
		for(i=0;i<n;i++)
			output = sum[n-1][i]>output?sum[n-1][i]:output;
		return output;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int i=0;
	for(;i<n;i++){
		int j=0;
		for(;j<=i;j++)
			scanf("%d", &value[i][j]);
	}
	printf("%d", downStair(n));
}

