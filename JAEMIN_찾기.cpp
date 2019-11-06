#include<stdio.h>  
char array[1501][1501];
int n, m;
int way;

void find(char a, int row, int col){
	for(int x=-1;x<=1;x++){
		for(int y=-1;y<=1;y++){
			if(x+row>=1 && x+row<=n && col+y>=0 && y+col<m){
				if(array[row+x][col+y]==a){
					if(a=='A'){
						find('E', row+x, col+y);
					}
					else if(a=='E'){	
						find('M', row+x, col+y);
					}
					else if(a=='M'){
						find('I', row+x, col+y);
					}
					else if(a=='I'){
						find('N', row+x, col+y);
					}
					else if(a=='N'){
						way++;
					}
				}
			}
		}
	}
}


int main(){
	scanf("%d %d", &n, &m);
	
	for(int i=1;i<=n;i++){
		scanf("%s", &array[i]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(array[i][j]=='J'){
				find('A', i, j);
			}
		}
	}
	
	printf("%d", way);
}
