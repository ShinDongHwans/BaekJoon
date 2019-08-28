#include<stdio.h>

int findSmallest(int input){
	int min = input;
	for(int i=0;i<3;i++){
		input = input/1000 + input%1000*10;
		if(min > input) min = input;
	}
	return min;
}

int findSmaller(int input){
	int count = 0;
	int sample = 1111;
	while(sample != input){
		if(sample%1000/100 == 0)
			sample+=100;
		else if(sample%100/10 == 0)
			sample+=10;
		else if(sample%10 == 0)
			sample+=1;
		if(sample == findSmallest(sample))
			count++;
		sample++;
	}
	return count;
}

int main(){
	int input;
	int sum=0;
	for(int i=0;i<4;i++){
		scanf("%d", &input);
		sum*=10;
		sum+=input;
	}
	printf("%d",findSmaller(findSmallest(sum))+1);
}