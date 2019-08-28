#include <stdio.h>

long long int n;



long long int sqrt(long long int k)
{
	for(long long int i=0; i<=k; i++){
		if(i*i <= k && k <(i+1)*(i+1))	return i;
	}
}
int main()
{
  scanf("%lld", &n);
  printf("%d\n", sqrt(n));
  return 0;
}

