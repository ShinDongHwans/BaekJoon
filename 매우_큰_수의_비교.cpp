#include<stdio.h>
#include<math.h>
int num1[1000000];
int num2[1000000];
int n;

int find(int x, int y){
	if(y%x==0)
		return x;
	for(int i=x/2;i>0;i--){
		if(y%i==0&&x%i==0){
			return i;
		}
	}
}

int compare(int x, int y){
	int div1, div2;
	int x1, x2;
	int y1, y2;
	if(y==n)
		return x;
	div1=find(num1[x], num1[y]);
	div2=find(num2[x], num2[y]);
	x1=num1[x]/div1;
	x2=num2[x]/div2;
	y1=num1[y]/div1;
	y2=num2[y]/div2;
	if(pow(x1, x2)>pow(y1, y2))
		return compare(x, y+1);
	else
		return compare(y, y+1);
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d %d", &num1[i], &num2[i]);
	printf("%d", compare(0, 1));
}
