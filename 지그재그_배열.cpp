#include <stdio.h>
int n, m;
int array[100][100]={};
int num=1;
int max;
int down(int, int);

int up(int x, int y){
	if(num>max)
		return 0;
	for(int i=0;x-i>-1&&y-i>-1;i++){
		array[x-i][y-i]=num;
		num++;
	}
	if(y<m-1)
		return up(x, y+1);
	else
		return up(x-1, y);
}

int down(int x, int y){
	if(num>max)
		return 0;
	for(int i=0;x+i<n&&y+i<m;i++){
		array[x+i][y+i]=num;
 		num++;
	}
	if(x>0)
		return down(x-1, y);
	else
		return down(x, y+1);
}
 
int main(){
	scanf("%d %d", &n, &m);
	max=n*m;
	up(n-1,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
}
