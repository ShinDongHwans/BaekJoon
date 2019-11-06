#include<stdio.h>
int array[8][8];
void lazer(int x, int y, char direction);


void splinter(int x, int y, char come){
	
	switch(come){
		case 'N':
			lazer(x, y, 'S');
			lazer(x, y, 'W');
			lazer(x, y, 'E');
			break;
		case 'S':
			lazer(x, y, 'N');
			lazer(x, y, 'W');
			lazer(x, y, 'E');
			break;
		case 'W':
			lazer(x, y, 'N');
			lazer(x, y, 'S');
			lazer(x, y, 'E');
			break;
		case 'E':
			lazer(x, y, 'N');
			lazer(x, y, 'S');
			lazer(x, y, 'W');
			break;
	}
}

void lazer(int x, int y, char direction){
	switch(direction){
		case 'E':
			for(int i=y; i<7;i++){
				if(array[x][i+1]==2){
					splinter(x, i+1, 'W');
				}
				else{
					array[x][i+1] = 1;
				}
			}
			break;
		case 'W':
			for(int i=y; i>1;i--){
				if(array[x][i-1]==2){
					splinter(x, i-1, 'E');
				}
				else{
					array[x][i-1] = 1;
				}
			}
			break;
		case 'N':
			for(int i=x; i>1;i--){
				if(array[i-1][y]==2){
					splinter(i-1, y, 'S');
				}
				else{
					array[i-1][y] = 1;
				}
			}
			break;
		case 'S':
			for(int i=x; i<7;i++){
				if(array[i+1][y]==2){
					splinter(i+1, y, 'N');
				}
				else{
					array[i+1][y] = 1;
				}
			}
			break;
	}
	
}

int main(){
	int x, y;
	int i, j;
	int n;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		array[x][y] = 2;
	}
	lazer(4, 0, 'E');
	for(i=1;i<8;i++){
		for(j=1;j<8;j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}
	
