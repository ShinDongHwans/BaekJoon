#include<stdio.h>
int saver[1001][10];

void sum(int index){
	int output;
	int i=1;
	for(;i<10;i++){
		saver[index][i]+=saver[index][i-1];
		saver[index][i]%=10007;
	}
		
}

int find(int index, int n){
	if(index==n+1){
		int output=0;
		int i=0;
		for(;i<10;i++)
			output+=saver[n][i];
			output%=10007;
			return output;
	}
	else{
		sum(index-1);
		int i=0;
		for(;i<10;i++)
			saver[index][i]=saver[index-1][i];
		return find(index+1, n);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	if(n==1){
		printf("10");
		return 0;
	}
	else{
		int i=0;
		for(;i<10;i++){
			saver[1][i]=1;
		}
		printf("%d", find(2, n));
		return 0;
	}
}
