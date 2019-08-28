#include<stdio.h>

int saver[301][301]={{0,},};

int cutting(int n, int m){
	if(n==1) return m-1;
	else if(m==1) return n-1;
	else if(saver[n][m] != 0) return saver[n][m];
	else if(n>m){
		int i=n/2;
		int x = cutting(i, m)+cutting(n-i, m)+1;
		saver[n][m] = x;
		return x;
	}
	else{
		int i=m/2;
		int x = cutting(n, m-i)+cutting(n, i)+1;
		saver[n][m] = x;
		return x;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", cutting(n, m));
} 
