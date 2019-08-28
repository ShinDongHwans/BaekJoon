#include<stdio.h>
int relation[50][50];
int score[50];
int hubos[50];
int relations;

void print(int num){
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			printf("%d ", relation[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int find(int x, int y, int num){
	int min = 100;
	for(int i=0;i<num;i++){
		if(i!=x && i!=y && relation[i][x]!=0 && relation[i][y]!=0){
			int mid = relation[i][x] + relation[i][y];
			if(mid < min) min = mid;
		}
	}
	if(min == 100) return -1;
	return min;
}

void makeRelation(int inputL, int num){
	int turn=2;
	while(relations!=0){
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				if(i!=j && relation[i][j] == 0){
					int re = find(i, j, num);
					if(re == turn){
						relation[i][j] = re;
						relation[j][i] = re;
						relations--;
					}
				}
			}
		}
		turn++;
	}
}

int scoring(int num){
	int min = 100;
	for(int i=0;i<num;i++){
		int max = 1;
		for(int j=0;j<num;j++)
			max = relation[i][j] > max ? relation[i][j]:max;
		score[i] = max;
		min = max < min ? max:min;
	}
	return min;
}

int findHubos(int num, int min){
	int index = 0;
	for(int i=0; i<num; i++){
		if(score[i] == min){
			hubos[index++] = i+1;
		}
	}
	return index;
}

int main(){
	int num;
	int pointer = 0;
	int sign=1;
	int x, y;
	scanf("%d", &num);
	relations = num*(num-1)/2;
	while(sign){
		scanf("%d %d", &x, &y);
		if(x==-1)
			sign = 0;
		else{
			relation[x-1][y-1] = 1;
			relation[y-1][x-1] = 1;
			relations--;
			pointer++;
		}
	}
	makeRelation(pointer, num);

	int minScore = scoring(num);
	int numOfHubos = findHubos(num, minScore);
	printf("%d %d\n", minScore, numOfHubos);
	for(int i=0;i<numOfHubos;i++)
		printf("%d ", hubos[i]);
}