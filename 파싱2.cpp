#include <stdio.h>
#include <string.h>
int main()
{
    char string[101]={};
    char * pt = string; 
    gets(string);
    for(int i=0;i<sizeof(string);i++){
    	if(*(pt+i) == 0)
    		break;
    	if(*(pt+i)==',')
	   		printf(" ");
    	else if (*(pt+i)==';'){
			printf(" \n");	
		}
		else if(*(pt+i)!=' '){
			printf("%c", *(pt+i));
		}
	}
	printf(" \n");
	return 0;
}
	
