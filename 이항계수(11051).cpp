#include<stdio.h>

int saver[1001][1001];

int calculate(int n, int k){
	if(n==1 || k==0 || n==k) return 1;
	else if(k==1||k==n-1) return n;
	else if(saver[n][k]!=0) return saver[n][k];
	else{
		saver[n][k] = (calculate(n-1, k) + calculate(n-1, k-1))%10007;
		return saver[n][k];
	}
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", calculate(n, k));
	return 0;
}
