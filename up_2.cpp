#include<stdio.h>
int map[19][19];
int copy_map[19][19];
int h, w;

void copy(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			copy_map[i][j]=map[i][j];
	}
}

int find(int x, int y, int k, int out){
	copy_map[x][y]=0;
	out++;
	if(x-1>=0&&copy_map[x-1][y]==k)
		out+=find(x-1, y, k, 0);
	if(x+1<h&&copy_map[x+1][y]==k)
		out+=find(x+1, y, k, 0);
	if(y-1>=0&&copy_map[x][y-1]==k)
		out+=find(x, y-1, k, 0);
	if(y+1<w&&copy_map[x][y+1]==k)
		out+=find(x, y+1, k, 0);
	return out;
}

int search(int n){
	int output=0;
	int candi;
	copy();
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(copy_map[i][j]==n){
				candi = find(i, j, n, 0);
				output=candi>output?candi:output;	
			}
		}
	}
	return output;
}

int main(){
	scanf("%d %d", &h, &w);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			scanf("%d", &map[i][j]);
	}
	
	for(int i=1;i<10;i++){
		int a=search(i);
		if(a)
			printf("%d %d\n", i, a);
		if(i!=1)
			printf("f");
	}
	
}
