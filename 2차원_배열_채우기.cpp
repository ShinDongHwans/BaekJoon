#include<stdio.h>

int n, m;
int array[101][101];

void straight_vertical(int x){
	for(int i=0;i<n;i++){
		array[i][x] = x*n+i+1;
	}
}

void reverse_vertical(int x){
	for(int i=0;i<n;i++){
		array[i][x] = x*n+n-i;
	}
}

void straight_horizontal(int x){
	for(int i=0;i<n;i++){
		array[x][i] = x*n+i+1;
	}
}

void reverse_horizontal(int x){
	for(int i=0;i<n;i++){
		array[x][i] = x*n+n-i;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		straight_horizontal(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}
