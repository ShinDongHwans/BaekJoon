#include <stdio.h>
#include <string.h>
char fomula[1000];
int num[100];
char str[100];
int number=0;
long int output=0;
int count_num = 0;
int count_str = 0;

int calculator(){
	int output=0;
	for(int i=0;i<count_num;i++){
		if(i==0)
			output+=num[i];
		else{
			if(str[i-1]=='+')
				output+=num[i];
			else if(str[i-1]=='-')
				output-=num[i];
			else if(str[i-1]=='*')
				output*=num[i];
			else if(str[i-1]=='/')
				output/=num[i];
		}
	}
	return output;
}

void check(char x){
		if(x=='+'){
			str[count_str]='+';
			count_str++;
			num[count_num]=number;
			number=0;
			count_num++;
		}
		else if(x=='-'){
			str[count_str]='-';
			count_str++;
			num[count_num]=number;
			number=0;
			count_num++;
		}
		else if(x=='*'){
			str[count_str]='*';
			count_str++;
			num[count_num]=number;
			number=0;
			count_num++;
		}
		else if(x=='/'){
			str[count_str]='/';
			count_str++;
			num[count_num]=number;
			number=0;
			count_num++;
		}
		else if(x=='='){
			num[count_num]=number;
			number=0;
			count_num++;
		}
		else{
			number*=10;
			number+=x-48;
		}	
}

int main(){
	int output;
	
	gets(fomula);
	
	for(int k=0;k<strlen(fomula);k++)
	{
		check(fomula[k]);
	}
	
	output=calculator();
	
	printf("%ld", output);
}
