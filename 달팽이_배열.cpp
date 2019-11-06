#include <stdio.h>
int array[100][100];
int n, m;
int num=1;
int i;
int east(int, int);

int north(int x, int y){
	for(i=0;x-i>-1;i++){
		if (num<1)
			return 0;
		if(array[x-i][y]==0){
			array[x-i][y]=num;
			num--;
		}
		else
			return east(x-i+1, y+1);
	}
	if(i==n)
		return east(x-i+1, y+1);
}
int west(int x, int y){
	for(i=0;y-i>-1;i++){
		if (num<1)
			return 0;
		if(array[x][y-i]==0){
			array[x][y-i]=num;
			num--;
		}
		else
			return north(x-1, y-i+1);
	}
	return north(x-1, y-i+1);
}
int south(int x, int y){
	for(i=0;x+i<n;i++){
		if (num<1)
			return 0;
		if(array[x+i][y]==0){
			array[x+i][y]=num;
			num--;
		}
		else{
			return west(x+i-1, y-1);
		}
	}
	return west(x+i-1, y-1);
}
int east(int x, int y){
	for(i=0;y+i<m;i++){
		if (num<1)
			return 0;
		if(array[x][y+i]==0){
			array[x][y+i]=num;
			num--;
		}
		else if(array[x][y+i]!=0){
			return south(x+1, y+i-1);	
		}
	}
	return south(x+1, y+i-1);
}

int main(){
	scanf("%d %d", &n, &m);
	num=n*m;
	north(n-1, 0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}
}
