#include <stdio.h>

int n;

long long int fibonaci(int x)
{
  if(x==1) return 1;
  if(x==2) return 1;
  else return fibonaci(x-1)+fibonaci(x-2);	
}

int main(){
	scanf("%d", &n);
	printf("%lld", fibonaci(n));
} 
