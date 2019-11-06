#include<stdio.h>
int i;
int a, b;

int LCA(int x, int y){
	if(x==y)
		return x;
	x/=2;
	i++;
	if(x<y)
		return LCA(y, x);
	else
		return LCA(x, y);
}

int print_ances(){
	if(a>b)
		printf("%d", LCA(a, b));
	else
		printf("%d", LCA(b, a));
}

int print_dis(){
	if(a>b)
		LCA(a, b);
	else
		LCA(b, a);
	printf("%d", i);
}

int main(){
	scanf("%d %d", &a, &b);
	print_dis();
}
