#include<stdio.h>

int f(int n, int m, int x, int y){
	for(int i=0;i<m;i++){
		if((n*i+x-y)%m==0)
			return n*i+x;
	}
	return -1;
}

int main(){
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int n, m, x, y;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		printf("%d\n", f(n, m, x, y));
	}
}
