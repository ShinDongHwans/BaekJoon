#include<stdio.h>

int price[1001];
float saver[1001];

int max(int x, int y){
	if(x>y) return x;
	else return y;
}

int search(int n){
	saver[1]=price[1];
	saver[2]=max(price[2], price[1]*2);
	int i=3;
	for(;i<=n;i++){
		int max=price[i];
		int j=1;
		for(;j<i;j++){
			int x = price[j] + saver[i-j];
			if(x>max)
				max=x;
		}
		saver[i]=max;
	}
	return saver[n];
}

int main(){
	int num=0;
	scanf("%d", &num);
	int i=1;
	for(;i<=num;i++){
		scanf("%d", &price[i]);
	}
	printf("%d",search(num));
} 
