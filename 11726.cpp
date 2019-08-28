#include<stdio.h>

int value[1001][3];
int input[1001][3][3];

int min(int a, int b){
	if(a<b) return a;
	else return b;
}

int minInput(int i, int color){
	if(color == 0){
		int a = input[i][0][1];
		int b = input[i][0][2];
		return min(a, b);
	}
	else if(color == 1){
		int a = input[i][1][0];
		int b = input[i][1][2];
		return min(a, b);
	}
	else if(color == 2){
		int a = input[i][2][1];
		int b = input[i][2][0];
		return min(a, b);
	}
}

int paint(int n){
	input[1][0][1] = value[1][0];
	input[1][0][2] = value[1][0];
	input[1][1][0] = value[1][1];
	input[1][1][2] = value[1][1];
	input[1][2][0] = value[1][2];
	input[1][2][1] = value[1][2];
	int i = 2;
	for(; i <=n ;i++){
		input[i][0][1] = minInput(i-1, 1) + value[i][0];
		input[i][0][2] = minInput(i-1, 2) + value[i][0];
		input[i][1][0] = minInput(i-1, 0) + value[i][1];
		input[i][1][2] = minInput(i-1, 2) + value[i][1];
		input[i][2][0] = minInput(i-1, 0) + value[i][2];
		input[i][2][1] = minInput(i-1, 1) + value[i][2];
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int i = 1;
	for(; i<n+1; i++){
		scanf("%d %d %d",  &value[i][0], &value[i][1], &value[i][2]);
	}
	paint(n);
	printf("%d", min(input[n][0][1], min(input[n][0][2], min(input[n][1][0], min(input[n][1][2], min(input[n][2][0], input[n][2][1]))))));
}

