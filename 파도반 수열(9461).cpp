#include<stdio.h>
long long int score[100]={1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12};

long long int find(int n){
	if(score[n]!=0) return score[n];
	else{
		long long int x = find(n-1)+find(n-5);
		score[n]=x;
		return x;
	}
}

int main(){
	int num;
	scanf("%d", &num);
	while(num-->0){
		int index;
		scanf("%d" ,&index);
		printf("%lld\n", find(index-1));
	}
}
