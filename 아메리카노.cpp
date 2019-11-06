#include <stdio.h>

int americano(int x, int y){
	int output=0;
	while(x>=y){
		output+=x/y;
		x=x%y+x/y;
	}
	return output;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", americano(n, k));
}
