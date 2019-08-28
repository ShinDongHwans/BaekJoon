#include<stdio.h>

int main(){
	char input[500];
	scanf("%s", input);
	int i=0;
	int sum=0;
	while(i>=0){
		if(input[i]!='\0')
			sum+=input[i++]-'0';
		else
			i=-1;
	}
	if(sum%3==0)
		printf("1");
	else
		printf("0");
} 
