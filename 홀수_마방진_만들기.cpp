#include<stdio.h>
int main(){
	int array[49][49] = {};
	int i=1, j;
	int x=0, y;
	int n;
	scanf("%d", &n);
	y=n/2;
	while(i!=n*n+1){
		array[x][y]=i;
		x--;
		y++;
		if(x<0 && y==n){
			if(array[n-1][0]==0){
				x=n-1;
				y=0;
			}
			else{
				x+=2;
				y--;
			}
		}
		else if(x<0){
			if(array[n-1][y]==0){
				x=n-1;
			}
			else{
				x+=2;
				y--;
			}
		}
		else if(y==n){
			if(array[x][0]==0){
				y=0;
			}
			else{
				x+=2;
				y--;
			}
		}
		else if(array[x][y]!=0){
				x+=2;
				y--;
		}
		i++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d ", array[i][j]);
		}
		printf("\n");
	}
}
	
