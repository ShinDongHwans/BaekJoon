#include <stdio.h>

int n;

int fibonaci(int x, int y)
{
  if(x==1) return 1;
  if(y==1||y==x) return 1;
  else return fibonaci(x-1,y-1)+fibonaci(x-1,y);
}

void g(int k, int l)
{
  if(l>k) return;
  g(k, l+1);
  printf("%d ", fibonaci(k, l));
}

void f(int k)
{
  if(k <= 0) return;
  f(k-1);
  g(k, 1);
  printf("\n");
}

int main()
{
  scanf("%d", &n);
  f(n);
}
