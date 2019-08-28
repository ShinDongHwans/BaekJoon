#include<stdio.h>
int map[4][4];
int dim[4][4];

void reset(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			dim[i][j]=0;
	}
}

int checkbin(int x){
	if(x==1)
		return 1;
	if(x%2==0)
		return checkbin(x/2);
	else
		return 0;
}
void change(int h1, int h2, int y){
	int c=map[h1][y];
	map[h1][y]=map[h2][y];
	map[h2][y]=c;
}
void change_y(int h, int y1, int y2){
	int c=map[h][y1];
	map[h][y1]=map[h][y2];
	map[h][y2]=c;
}
int above(int k, int y){
	while(k!=0){
		if(map[k-1][y]!=0)
			return k-1;
		k--;
	}
	return -1;
}
int below(int k, int y){
	while(k!=3){
		if(map[k+1][y]!=0)
			return k+1;
		k++;
	}
	return -1;
}
int righten(int k, int y){
	while(y!=3){
		if(map[k][y+1]!=0)
			return y+1;
		y++;
	}
	return -1;
}
int leften(int k, int y){
	while(y!=0){
		if(map[k][y-1]!=0)
			return y-1;
		y--;
	}
	return -1;
}

void up(){
	for(int i=1;i<4;i++){
		for(int j=0;j<4;j++){
			int x=above(i, j);
			if(x!=-1){
				if(map[i][j]==map[x][j]&&dim[x][j]==0){
					map[x][j]*=2;
					map[i][j]=0;
					dim[x][j]++;
				}
				else
					change(i, x+1, j);
			}
			else{
				change(i, 0, j);
			}
		}
	}
	reset();
}

void down(){
	for(int i=2;i>=0;i++){
		for(int j=0;j<4;j++){
			int x=below(i, j);
			if(x!=-1){
				if(map[i][j]==map[x][j]&&dim[x][j]==0){
					map[x][j]*=2;
					map[i][j]=0;
					dim[x][j]++;
				}
				else
					change(i, x-1, j);
			}
			else{
				change(i, 3, j);
			}
		}
	}
	reset();
}

void right(){
	for(int i=0;i<4;i++){
		for(int j=2;j>=0;j--){
			int x=righten(i, j);
			if(x!=-1){
				if(map[i][j]==map[i][x]&&dim[i][x]==0){
					map[i][x]*=2;
					map[i][j]=0;
					dim[i][x]++;
				}
				else
					change_y(i, x-1, j);
			}
			else{
				change_y(i, 3, j);
			}
		}
	}
	reset();
}

void left(){
	for(int i=0;i<4;i++){
		for(int j=1;j<4;j++){
			int x=leften(i, j);
			if(x!=-1){
				if(map[i][j]==map[i][x]&&dim[i][x]==0){
					map[i][x]*=2;
					map[i][j]=0;
					dim[i][x]++;
				}
				else
					change_y(i, x+1, j);
			}
			else{
				change_y(i, 0, j);
			}
		}
	}
	reset();
}

void print_map(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int sum=0;
	int direction='U';
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d", &map[i][j]);
			sum+=map[i][j];
		}
	}
	switch(direction){
		case 'U':
			up();
			break;
		case 'D':
			down();
			down();
			down();
			break;
		case 'R':
			right();
			right();
			right();
			break;
		case 'L':
			left();
			left();
			left();
			break;
	}
	print_map();
}

