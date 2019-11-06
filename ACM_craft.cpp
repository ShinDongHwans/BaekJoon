#include<stdio.h>
#include<math.h>

int build[1000];
int connect[100000][2];

int find(int n, int k, int s){
	int output=connect; 
	while(s==n){
		for(int i=0;i<n;i++){
			if(connect[i][0]==s){
				output+=build[connect[i][1]]
			}
		}
	}
}

void start_game(int n, int k){
	int output;
	for(int i=0;i<n;i++)
		scanf("%d", &build[i]);
	for(int i=0;i<k;i++){
		scanf("%d %d", &connect[i][0], &connect[i][1]);
	}
	output=find(n, k, 1);		
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++){	
		int num, k;		
		scanf("%d %d", &num, &k);
		start_game(num, k);
	}
}
