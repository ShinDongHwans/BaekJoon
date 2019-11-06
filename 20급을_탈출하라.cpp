#include<stdio.h>
int mana;
int num;
int cost[10];
int yeah=0;

int fuck(int n, int del){
	
}

int find(int n, int del){
	if(del<0)
		return 0;
	if(del==0){
		yeah=-1;
		return 0;
	}
	if(n==-1){
		return 0;
	}
	int diff=del-cost[n];
	if(yeah==0)
		find(n-1, diff);
	if(yeah==-1)
		cost[n]=-1;
	if(yeah==0)
		find(n-1, del);
	if(yeah==-1)
		return 0;
	return 0;
}

void check(){
	int sum=0;
	int start=-1;
	for(int i=0;i<num;i++){
		if(cost[i]!=-1)
			sum+=cost[i];
	}
	sum=sum-mana;
	if(sum==0)
		return;
	for(int i=num-1;i>-1;i--){
		if(cost[i]!=-1&&cost[i]<sum){
			start=i;
			find(start, sum);
			break;
		}
		if(cost[i]==sum){
			cost[i]=-1;
			return;
		}
	}
	if(yeah==0)
	fuck(start, sum);
}

void print(){
	for(int i=0;i<num;i++){
		if(cost[i]!=-1)
			printf("%d ", cost[i]);
	}
}

int main(){
	scanf("%d\n%d", &mana, &num);
	for(int i=0;i<num;i++){
		scanf("%d", &cost[i]);
		if(cost[i]>mana)
			cost[i]=-1;
	}
	if(cost[0]==-1){
		printf("-1");
		return 0;
	}
	check();
	print();
}
