#include<stdio.h>

int num;
int schedule[1001][2];
int dp[1001];

int max(){
	int i, output=0;
	for(i=1;i<=num;i++){
		if(output < dp[i])
			output = dp[i];
	}
	return output;
}

int find(int index){
	if(index == 0) return max();
	else{
		int x = num - (schedule[index][0]-1+index);
		int i;
		if(x>=0){
			for(i=0;i<=x;i++){
				int k = schedule[index][1] + dp[index + schedule[index][0]+i];
				if(dp[index] < k)
					dp[index]=k;
			}
		}
		for(i=index+1;i<=num;i++){
			int k = dp[i];
			if(dp[index] < k)
				dp[index]=k;
		}
		return find(index-1);a
	}
}

int main(){
	int i;
	scanf("%d", &num);
	for(i=1;i<=num;i++)
		scanf("%d %d", &schedule[i][0], &schedule[i][1]);
	printf("%d", find(num));
}
