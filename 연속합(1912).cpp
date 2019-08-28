#include<stdio.h>


int main(){
	int num;
	int score[100000];
	int save[100000][2];
	int output = -2147483648;
	scanf("%d", &num);
	int i = 0;
	for(;i<num;i++)
		scanf("%d" ,&score[i]);
 	save[0][0] = score[0];
 	save[0][1] = score[0];
 	output = save[0][0];
	for(i=1;i<num;i++){
		save[i][0] = save[i-1][0] + score[i];
		if(save[i][0] < save[i-1][1])
			save[i][1] = save[i][0];
		else
			save[i][1] = save[i-1][1];
	}
	for(int i=0;i<num;i++){
		if(save[i][1] < 0 && save[i][0]!=save[i][1]){
			if(save[i][0] - save[i][1] > output)
				output = save[i][0] - save[i][1];
		}
		else{
			if(save[i][0] > output)
				output = save[i][0];
			if(score[i] > output)
				output = score[i];
		}
	}
	printf("%d", output);
	return 0;
}

