#include <stdio.h>
#include <string.h>
char aroma[40];
int num[20];
char symbol[20];

int check_symbol(char letter){
	if(letter=='I')
		return 1;
	else if(letter=='V')
		return 5;
	else if(letter=='X')
		return 10;
	else if(letter=='L')
		return 50;
	else if(letter=='C')
		return 100;
	else if(letter=='D')
		return 500;
	else if(letter=='M')
		return 1000;
	
}

int main()
{
	int output=0;
	scanf("%s", &aroma);
	for(int i=0;i<strlen(aroma);i++){
		if(i%2==0)
			num[i/2]=aroma[i]-48;
		else
			symbol[i/2]=aroma[i];
			
	}
	for(int i=0;i<strlen(symbol);i++){
		if(i==strlen(aroma)-1)
			output+=num[i]*check_symbol(symbol[i]);
		else{
			if(check_symbol(symbol[i])>=check_symbol(symbol[i+1]))
				output+=num[i]*check_symbol(symbol[i]);
			else
				output-=num[i]*check_symbol(symbol[i]);
		}
		
	}
	printf("%d", output);
}
