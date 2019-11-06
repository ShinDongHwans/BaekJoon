#include<stdio.h>
int onetagon[2][10000];
int copytagon[2][10000];
int candi[2][10000];

void make_onetagon(int n){
	for(int i=0;i<n;i++){
		scanf("%d", &onetagon[0][i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &onetagon[1][i]);
	}
}

void copy(int n){
	for(int i=0;i<n;i++){
		copytagon[0][i]=onetagon[0][i];
		copytagon[1][i]=onetagon[1][i]; 
	}
}

void check(int i, int j, int n, int m){
	if(i==0){
		if(j==0){
			if(copytagon[i][j]+copytagon[i][n-1]<=m){
				candi[i][j]++;
				candi[i][n-1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i][j+1]<=m){
				candi[i][j]++;
				candi[i][j+1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i+1][j]<=m){
				candi[i][j]++;
				candi[i+1][j]++;
				return;
			}
		}
		else if(j==n-1){
			if(copytagon[i][j]+copytagon[i][0]<=m){
				candi[i][j]++;
				candi[i][0]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i][j-1]<=m){
				candi[i][j]++;
				candi[i][j-1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i+1][j]<=m){
				candi[i][j]++;
				candi[i+1][j]++;
					return;
			}
		}
		else{
			if(copytagon[i][j]+copytagon[i][j+1]<=m){
				candi[i][j]++;
				candi[i][j+1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i][j-1]<=m){
				candi[i][j]++;
				candi[i][j-1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i+1][j]<=m){
				candi[i][j]++;
				candi[i+1][j]++;
				return;
			}
		}
	}
	else{
		if(j==0){
			if(copytagon[i][j]+copytagon[i][n-1]<=m){
				candi[i][j]++;
				candi[i][n-1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i][j+1]<=m){
				candi[i][j]++;
				candi[i][j+1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i-1][j]<=m){
				candi[i][j]++;
				candi[i-1][j]++;
				return;
			}
		}
		else if(j==n-1){
			if(copytagon[i][j]+copytagon[i][0]<=m){
				candi[i][j]++;
				candi[i][0]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i][j-1]<=m){
				candi[i][j]++;
				candi[i][j-1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i-1][j]<=m){
				candi[i][j]++;
				candi[i-1][j]++;
				return;
			}
		}
		else{
			if(copytagon[i][j]+copytagon[i][j+1]<=m){
				candi[i][j]++;
				candi[i][j+1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i][j-1]<=m){
				candi[i][j]++;
				candi[i][j-1]++;
				return;
			}
			
			if(copytagon[i][j]+copytagon[i-1][j]<=m){
				candi[i][j]++;
				candi[i-1][j+1]++;
				return;
			}
		}
	}
	return;
}

int rest(int n){
	int output=0;
	for(int i=0;i<n;i++){
		if(copytagon[0][i]>0)
			output++;
		if(copytagon[1][i]>0)
			output++;	
	}
	return output;
}

int minimization(int n){
	for(int i=0;i<n;i++){
		if(candi[0][i]==3){
			
		}
	}
}

int analyzing(int n, int m){
	int output=0;
	copy(n);
	for(int i=0;i<n;i++){
		check(0, i, n, m);
		check(1, i, n, m);
	}
	output+=minimization(n);
	output+=rest(n);
	return output;
}

void invasion(int n, int member){
	int output;
	make_onetagon(n);
	printf("%d",analyzing(n, member));
}

void reset(int n){
	for(int i=0;i<n;i++){
		onetagon[0][i]=0;
		onetagon[1][i]=0;
		candi[0][i]=0;
		candi[1][i]=0;
	}
}

int main(){
	int test;
	scanf("%d", &test);
	for(int i=0;i<test;i++){
		int n, k;
		scanf("%d %d", &n, &k);
		invasion(n, k);
		reset(n);
	}
}
