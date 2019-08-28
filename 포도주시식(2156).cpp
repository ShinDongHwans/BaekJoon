#include<stdio.h>

int num;
int score[10001];
int save[10001][3];

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

void drink(){
	save[1][0] = 0;
	save[1][1] = score[1];
	save[1][2] = 0;
	save[2][0] = score[1];
	save[2][1] = score[2];
	save[2][2] = score[1] + score[2];

	for(int i = 3; i<=num; i++){
		save[i][0] = max(save[i-1][0], max(save[i-1][2], save[i-1][1]));
		save[i][1] = max(save[i-1][0],max(save[i-2][1], save[i-2][2]))+score[i];
		save[i][2] = save[i-1][1] + score[i];
	}
	return;
}

int main(){
	scanf("%d", &num);
	int i = 1;
	for(;i<=num;i++)
		scanf("%d" ,&score[i]);
	if(num == 1)
		printf("%d", score[1]);
	else{
		drink();
		printf("%d", max(save[num][0], max(save[num][1], save[num][2])));	
	}
	return 0;
}

