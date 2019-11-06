#include <stdio.h>
int array[150][150];
int n;
int num=1;
int i;
int west(int, int);
int south(int, int);
int east(int, int);

int north(int x, int y){
	for(i=0;x-i>-1;i++){
		if (num>n*n)
			return 0;
		if(array[x-i][y]==0){
			array[x-i][y]=num;
			num++;
		}
		else
			return west(x-i+1, y-1);
	}
	return west(x-i+1, y-1);
}
int west(int x, int y){
	for(i=0;y-i>-1;i++){
		if (num>n*n)
			return 0;
		if(array[x][y-i]==0){
			array[x][y-i]=num;
			num++;
		}
		else
			return south(x+1, y-i+1);
	}
	return south(x+1, y-i+1);
}
int south(int x, int y){
	for(i=0;x+i<n;i++){
		if (num>n*n)
			return 0;
		if(array[x+i][y]==0){
			array[x+i][y]=num;
			num++;
		}
		else{
			return east(x+i-1, y+1);
		}
	}
	if(i==n)
		return east(x+i-1, y+1);
}
int east(int x, int y){
	for(i=0;y+i<n;i++){
		if (num>n*n)
			return 0;
		if(array[x][y+i]==0){
			array[x][y+i]=num;
			num++;
		}
		else
			north(x-1, y+i-1);
	}
	if(i==n) 
		return north(x-1, y+i-1);
}
	
int main(){
	scanf("%d", &n);
	south(0, 0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
}
