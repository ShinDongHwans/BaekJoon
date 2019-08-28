#include<stdio.h>

int size;
int unknown;
int map[20][20];
int numlow[20], numcol[20];
int low[20][10], column[20][10];

void initializing(){
	for(int i=0; i<size; i++){
		for(int v=0; v<size-i; v++){
			map[i][v] = 2;
		}
	}
	unknown = size*(size+1)/2;
}

void scan(int input1[][10], int*input2){
	for(int i=0; i<size; i++){
		scanf("%d", &input2[i]);
		for(int j=0; j<input2[i]; j++)
			scanf("%d", &input1[i][j]);
	}
}

int searchinglow(){
	for(int i=0; i<size; i++){
		int sum = 0;
		for(int j=0; j<numlow[i]; j++)
			sum+=low[i][j]+1;
		sum-=1;
		
		if(sum > size - i) return 1;
		if(sum == size - i){
			int pointer = 0;
			for(int j=0; j<numlow[i]; j++){
				for(int k=0; k< low[i][j]; k++){
					if(map[i][pointer] == 2) unknown--;
					map[i][pointer++] = 1;
				}
				if(map[i][pointer] == 2) unknown--;
				map[i][pointer++] = 0;
			}
			numlow[i] = 0;
		}
		else if(sum == -1){
			for(int j=0; j<size-i; j++){
				if(map[i][j] == 2) unknown--;
				map[i][j] = 0;
			}
			numlow[i] = 0;
		}
	}
	return 0;
}

int searchingcol(){
	for(int i=0; i<size; i++){
		int sum = 0;
		for(int j=0; j<numcol[i]; j++){
			sum+=column[i][j]+1;
		}
		sum-=1;
		
		if(sum > size - i) return 1;
		if(sum == size - i){
			int pointer = 0;
			for(int j=0; j<numcol[i]; j++){
				for(int k=0; k< column[i][j]; k++){
					if(map[pointer][i] == 0) return 1;
					if(map[pointer][i] == 2) unknown--;
					map[pointer++][i] = 1;
				}
				if(map[pointer][i] == 1) return 1;
				if(map[pointer][i] == 2) unknown--;
				map[pointer++][i] = 0;
			}
			numcol[i] = 0;
		}
		else if(sum == -1){
			for(int j=0; j<size-i; j++){
				if(map[j][i] == 2) unknown--;
				map[j][i] = 0;
			}
			numcol[i] = 0;
		}
	}
	return 0;
}

int makelow(int turn){
	for(int i=0; i<size; i++){
		if(numlow[i] > turn){
			int pointer = 0;
			int count = 0;
			int check = 1;
			while(check){
				while(map[i][pointer] < 1 && pointer < size)
					pointer++;
				if(map[i][pointer] == 1){
					if(count == turn){
						int x = low[i][turn];
						if(x != 0 && pointer + x -1 < size){
							for(int k = pointer+x; pointer<k; pointer++){
								if(map[i][pointer] == 0) return 1;
								if(map[i][pointer] == 2) unknown--;
								map[i][pointer] = 1;
							}
							if(numlow[i] == turn+1){
								for(;pointer < size-i; pointer++){
									if(map[i][pointer] == 2){
										unknown--;
										map[i][pointer] = 0;
									}
								}
								numlow[i]=0;
							}
							else{
								if(map[i][pointer] == 1) return 1;
								if(map[i][pointer] == 2) unknown--;
								map[i][pointer] = 0;
							}
							check = 0;
						}
						else return 1;
					}
					else{
						while(map[i][pointer]==1)
							pointer++;
						count++;
					}
				}
				else check = 0;
			}
		}
	}
	for(int i=0; i<size; i++){
		if(numlow[i] > turn){
			int pointer = size-i;
			int count = 0;
			int check = 1;
			while(check){
				while(map[i][pointer] < 1 && pointer > -1)
					pointer--;
				if(map[i][pointer] == 1){
					if(count == turn){
						int x = low[i][numlow[i]-turn-1];
						if(x != 0 && pointer - x + 1> -1){
							for(int k = pointer-x; pointer>k; pointer--){
								if(map[i][pointer] == 0) return 1;
								if(map[i][pointer] == 2) unknown--;
								map[i][pointer] = 1;
							}
							if(numlow[i] == turn+1){
								for(;pointer > -1; pointer--){
									if(map[i][pointer] == 2){
										unknown--;
										map[i][pointer] = 0;
									}
								}
								numlow[i]=0;
							}
							else{
								if(map[i][pointer] == 1) return 1;
								if(map[i][pointer] == 2) unknown--;
								map[i][pointer] = 0;
							}
							check = 0;
						}
						else return 1;
					}
					else{
						while(map[i][pointer]==1)
							pointer++;
						count++;
					}
				}
				else check = 0;
			}
		}
	}
	return 0;
}

int makecol(int turn){
	for(int i=0; i<size; i++){
		if(numcol[i] > turn){
			int pointer = 0;
			int count = 0;
			int check = 1;
			while(check){
				while(map[pointer][i] < 1 && pointer < size)
					pointer++;
				if(map[pointer][i] == 1){
					if(count == turn){
						int x = column[i][turn];
						if(x != 0 && pointer + x -1< size){
							for(int k = pointer+x; pointer<k; pointer++){
								if(map[pointer][i] == 0) return 1;
								if(map[pointer][i] == 2) unknown--;
								map[pointer][i] = 1;
							}
							if(numcol[i] == turn+1){
								for(;pointer < size-i; pointer++){
									if(map[pointer][i] == 2){
										unknown--;
										map[pointer][i] = 0;
									}
								}
								numcol[i]=0;
							}
							else{
								if(map[pointer][i] == 1) return 2;
								if(map[pointer][i] == 2) unknown--;
								map[pointer][i] = 0;
							}
							check = 0;
						}
						else return 3;
					}
					else{
						while(map[pointer][i]==1)
							pointer++;
						count++;
					}
				}
				else check = 0;
			}
		}
	}
	for(int i=0; i<size; i++){
		if(numcol[i] > turn){
			int pointer = size-i;
			int count = 0;
			int check = 1;
			while(check){					
				while(map[pointer][i] < 1 && pointer > -1)
					pointer--;
				if(map[pointer][i] == 1){
					if(count == turn){
						int x = column[i][numcol[i]-turn-1];
						if(x != 0 && pointer - x +1 > -1){
							for(int k = pointer-x; pointer>k; pointer--){
								if(map[pointer][i] == 0) {
									return 4;
								}
								if(map[pointer][i] == 2) unknown--;
								map[pointer][i] = 1;
							}
							if(numcol[i] == turn+1){
								for(;pointer > -1; pointer--){
									if(map[pointer][i] == 2){
										unknown--;
										map[pointer][i] = 0;
									}
								}
								numcol[i]=0;
							}
							else{
								if(map[pointer][i] == 1) return 5;
								if(map[pointer][i] == 2) unknown--;
								map[pointer][i] = 0;
							}
							check = 0;
						}
						else return 6;
					}
					else{
						while(map[pointer][i]==1)
							pointer--;
						count++;
					}
				}
				else check = 0;
			}
		}
	}
	return 0;
}

void printAll(){
	printf("numlow = [");
	for(int i=0; i<size; i++){
		printf("%d ", numlow[i]);
	}
	printf("]\n");
	
	printf("numcol = [");
	for(int i=0; i<size; i++){
		printf("%d ", numcol[i]);
	}
	printf("]\n");

	
	printf("low = \n[");
	for(int i=0; i<size; i++){
		printf("[");
		for(int j=0; j<size; j++){
			printf("%d ", low[i][j]);
		}
		printf("]\n");
	}
	printf("]\n");

	printf("col = \n[");
	for(int i=0; i<size; i++){
		printf("[");
		for(int j=0; j<size; j++){
			printf("%d ", column[i][j]);
		}
		printf("]\n");
	}
	printf("]\n");
}

void printAnswer(){
	for(int i=0; i<size; i++){
		for(int v=0; v<size-i-1; v++){
			printf("%d ", map[i][v]);
		}
		printf("%d\n", map[i][size-i-1]);
	}
}

int main(){
	scanf("%d", &size);
	initializing();
	scan(low, numlow);
	scan(column, numcol);
	if(searchinglow()){
		printf("No Answer");
	}
	printAnswer();
	printAll();
	if(searchingcol()){
		printf("No Answer");
	}
	printAnswer();
	printAll();
	int turn = 0;
	while(unknown != 0 && turn < 11){
		if(makelow(turn)){		
			printf("No Answer");
			return 0;
		}
		if(makecol(turn)){
			printf("No Answer");
			return 0;
		}

		if(makelow(turn)){	
			printf("No Answer");	
			return 0;
		}

		if(makecol(turn++)){	
			printf("No Answer");
			return 0;
		}
		printAnswer();
	}
	makecol(0);
	makelow(1);
	printAnswer();
	return 0;
}