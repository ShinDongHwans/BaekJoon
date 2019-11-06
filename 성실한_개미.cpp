#include<stdio.h>
int main(){
	int plate[10][10]={};
	int i, j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			scanf("%d", &plate[i][j]);
	
	if(plate[1][1]){
		for(i=0;i<10;i++){
			for(j=0;j<10;j++)
				printf("%d ", plate[i][j]);
			printf("\n");
		}
		return 0;
	}

	plate[1][1] = 9;
	i=1;
	for(j=1;j<10;j++){
		if(plate[i][j+1]==0){
			plate[i][j+1] = 9;
		}
		else if(plate[i][j+1]==2){
			plate[i][j+1] = 9;
			break;
		}
		else{
			while(plate[i][j+1] == 1 && plate[i+1][j] == 0 && i<10){
				plate[i+1][j]=9;
				i++;
			}
						
			if(plate[i][j+1] == 0){
				plate[i][j+1] = 9;	
			}
			else if(plate[i][j+1] == 2){
				plate[i][j+1] = 9;
				break;
			}
			else if(plate[i+1][j] == 2){
				plate[i+1][j] = 9;
				break;
			}
			else
				break;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			printf("%d ", plate[i][j]);
		printf("\n");
	}
}
