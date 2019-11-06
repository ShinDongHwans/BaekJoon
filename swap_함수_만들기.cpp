#include<stdio.h> 

void myswap(int * a, int * b){
	if(*a > *b){
		int c;
		c=*a;
		*a=*b;
		*b=c;
	}
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	myswap(&a, &b);
	printf("%d %d", a, b);
}
