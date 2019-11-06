#include<stdio.h>
int charge[8]={50000, 10000, 5000, 1000, 500, 100, 50, 10};
int main(){
	int n;
	int output=0;
	scanf("%d", &n);
	for(int i=0;i<8;i++){
		output+=n/charge[i];
		n%=charge[i];
	}
	printf("%d", output);
}
