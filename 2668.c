#include<stdio.h>

int num;
int location[101][101] = {{0,},};
int count[101] = {0, };
int counting[101] = {0, };
int output=0;
int hubo[101];
int outputs[101];

void printall(){
	printf("location => \n");
	for(int i=1; i<num+1; i++){
		for(int j=0; j<count[i]; j++){
			printf("%d ", location[i][j]);
		}
		printf("\n");
	}
	printf("count => \n");	
	for(int i=1; i<num+1; i++){
		printf("%d ", count[i]);
	}
	printf("\n");
	
	printf("counting => \n");	
	for(int i=1; i<num+1; i++){
		printf("%d ", counting[i]);
	}
	printf("\n");

	printf("hubo => \n");	
	for(int i=0; i<num; i++){
		printf("%d ", hubo[i]);
	}
	printf("\n");

	printf("outputs => \n");	
	for(int i=0; i<num; i++){
		printf("%d ", outputs[i]);
	}
	printf("\n");
}

void sorting(int count, int max) {
	if (count == max) return;
	else {
		int min = 101;
		int index = -1;
		for (int i = 0; i < max; i++) {
			if (min > hubo[i]) {
				index = i;
				min = hubo[i];
			}
		}
		outputs[count] = min;
		hubo[index] = 101;
	}
	return sorting(count+1, max);
}

int main(){
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		int input;
		scanf("%d", &input);
		location[input][count[input]++] = i+1;
		counting[input]++;
	}


	for(int c=1;c<num+1;c++){
		for(int i=1; i<num+1; i++){
			if(counting[i]!=0){
				for(int j=0; j<count[i]; j++){
					if(location[i][j] != -1 && counting[location[i][j]] == 0){
						location[i][j] = -1;
						counting[i]--;
					}
				}
			}
		}
	}
	
	for(int i=1; i<num+1; i++){
		if(counting[i]>0){
			for(int j=0; j< count[i]; j++){
				if(location[i][j]!=-1)
					hubo[output++] = location[i][j];
			}
		}
	}
	
	sorting(0, output);
	
	printf("%d\n", output);
	for(int i=0; i<output; i++)
		printf("%d\n", outputs[i]);
}