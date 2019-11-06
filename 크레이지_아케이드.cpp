#include<stdio.h>

int array[11][11]={};
int live[9]={};


void boom(int x, int y){
	int range = array[x][y];
	array[x][y]=-2;
	for(int i=1;i<=range;i++){
		if(x+i<11){
			if(array[x+i][y]==-1)
				break;
			else if(array[x+i][y]<=0)
				array[x+i][y]=-2;
		}
	}
	for(int i=1;i<=range;i++){
		if(x-i>0){
			if(array[x-i][y]==-1)
				break;
			else if(array[x-i][y]<=0)
				array[x-i][y]=-2;
		}
	}
	for(int i=1;i<=range;i++){
		if(y+i<11){
			if(array[x][y+i]==-1)
				break;
			else if(array[x][y+i]<=0)
				array[x][y+i]=-2;
		}
	}
	for(int i=1;i<=range;i++){
		if(y-i>0){
			if(array[x][y-i]==-1)
				break;
			else if(array[x][y-i]<=0)
				array[x][y-i]=-2;
		}
	}
}

int main(){
	int i, j;
	int x, y; 
	int n;
	
	for(i=1;i<11;i++){
		for(j=1;j<11;j++){
			scanf("%d", &array[i][j]);
		}
	}
	
	for(i=1;i<11;i++){
		for(j=1;j<11;j++){
			if (array[i][j]>=1){
				boom(i, j);
			}
		}
	}
	
	scanf("%d", &n);
	
	for(i=1;i<n+1;i++){
		scanf("%d %d", &x, &y);
		if(array[x][y]==-2)
			live[i]=1;
		else
			array[x][y] = i;
	}
	
	for(i=1;i<11;i++){
		for(j=1;j<11;j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	printf("Character Information\n");
	
	for(i=1;i<n+1;i++){
		if(live[i]==0)
			printf("player %d survive\n", i);
		else
			printf("player %d dead\n", i);
	}
}
