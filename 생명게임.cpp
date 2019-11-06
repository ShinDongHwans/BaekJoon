#include<stdio.h>
int a, b;
int array1[171][171];
int array2[171][171];
int x, y, z;

int find(int m, int n){
	int live = 0;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i+m>=1 && i+m<=a && j+n>=1 && j+n<=b && i*i+j*j!=0){
				live+=array1[m+i][n+j];
			}
		}
	}
	return live;
}

void future(int m, int n){
	int lives = find(m, n);
	if(lives == x && array1[m][n]==0){
		array2[m][n]=1;
	}
	else if((lives >= z || lives < y)&& array1[m][n]==1){
		array2[m][n]=0;
	} 
	else if((lives >=y || lives < z)&& array1[m][n]==1){
		array2[m][n]=1;
	}
}

int main(){
	scanf("%d %d", &a, &b);
	scanf("%d %d %d", &x, &y, &z);
	int i, j, p;
	int k;
	for(i=1;i<a+1;i++){// 배열 입력받기 
		for(j=1;j<b+1;j++){
			scanf("%d", &array1[i][j]);
		}
	}
	scanf("%d", &k);
	for(p=0;p<k;p++){
		for(i=1;i<a+1;i++){ // 미래의 세계 만들기 
			for(j=1;j<b+1;j++){
				future(i, j);
			}
		}
	}
	printf("\n");
	for(i=1;i<a+1;i++){ // 미래 세계 출력 
		for(j=1;j<b+1;j++){
			printf("%d ", array2[i][j]);
		}
		printf("\n");
	}
} 
	
