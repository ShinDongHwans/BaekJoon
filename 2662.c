#include<stdio.h>
int fund;
int num;
int company[20][301];
int paths[20];
int moneys[20];
int max = 0;

void find(int index, int sum, int money){
	if(money == 0){
		if(max < sum){
			max = sum;
			for(int i = index; i<num; i++)
				paths[i] = 0;
			for(int i=0;i<num;i++)
				moneys[i]=paths[i];
		}
	}
	else if(index == num-1) {
		if(max < sum + company[index][money]){
			max = sum + company[index][money];
			paths[index] = money;
			for(int i=0;i<num;i++)
				moneys[i]=paths[i];
		}
	} 
	else{
		for(int i=0;i<money;i++){
			paths[index]=i;
			find(index+1, sum+company[index][i], money-i);
		}
	}
}

int main(){
	scanf("%d %d", &fund, &num);
	for(int i=0;i<fund;i++){
		int money;
		scanf("%d", &money);
		for(int j=0;j<num;j++)
			scanf("%d", &company[j][money]);
	}
	find(0, 0, fund);
	printf("%d\n", max);
	for(int i=0;i<num;i++){
		printf("%d ", moneys[i]);
	}
}