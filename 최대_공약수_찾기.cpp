#include<stdio.h>
#include<math.h>
int find(int x, int y){
	if(y%x==0)
		return x;
	for(int i=x/2;i>0;i--){
		if(y%i==0&&x%i==0){
			return i;
		}
	}
	
}

int main(){
	int a, b;
	scanf("%d &d", &a, &b);
	if(a==1||b==1){
		printf("1");
		return 0;
	}
	if(a>b)
		printf("%d", find(b, a));
	else
		printf("%d", find(a, b));
} 
