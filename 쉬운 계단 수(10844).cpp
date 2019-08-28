#include<stdio.h>


int main(){
	int num;
	int save[100][10] = {{0,},};
	int output=0; 
	scanf("%d", &num);
	int i=0;
	for(;i<10;i++){
		save[0][i] = 1;
	}
	for(i=1;i<num;i++){
		int j=0;
		for(;j<10;j++){
			if(j==0) save[i][0]=save[i-1][1];
			else if(j==9) save[i][9] = save[i-1][8];
			else save[i][j] = (save[i-1][j-1]+save[i-1][j+1])%1000000000;
		}
	}
	for(i=1;i<10;i++){
		output+=save[num-1][i];
		output%=1000000000;
	}
		
	printf("%d", output);
	return 0;
}

