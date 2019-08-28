#include<stdio.h>

int div_up(int n, int m){
	if(n%m!=0) return n/m+1;
	else return n/m;
}

int main(){
	int up, down, height;
	scanf("%d %d %d", &up, &down, &height);
	printf("%d", div_up(height-up, up-down)+1);
	return 0;
}
