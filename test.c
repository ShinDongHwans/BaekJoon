#include<stdio.h>

int num;
int score[300];
int max = 0;

void climbUp(int index, int state, int sum){
	if(index == num-1){
		if(sum > max){
			printf("sum is %d\n", sum);
			max = sum;
		}
		return;
	}
	else if(state == 2){
		if(index == num-2) return;
		else return climbUp(index+2, 0, sum + score[index+2]);
	}
	else{
		climbUp(index+1, state+1, sum + score[index+1]);
		climbUp(index+2, 0, sum + score[index+2]);
		return;
	}
}

int main(){
	scanf("%d", &num);
	int i = 0;
	for(;i<num;i++)
		scanf("%d" ,&score[i]);
	climbUp(-1, 0, 0);
	printf("%d", max);
}
