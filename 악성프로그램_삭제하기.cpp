#include<stdio.h>
#include <string.h>
int main(){
	int n;
	int virus=0;
	char string[105][55]={};
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		gets(string[i]);
		if (strlen(string[i])<=3){
			printf("%s\n", string[i]);
			virus++;
		}
		else{
			for(int j=0;j<strlen(string[i]);j++){
				if((string[i][j]=='t'&&string[i][j+1]=='a'&&string[i][j+2]=='p')||(string[i][j]=='x'&&string[i][j+1]=='o'&&string[i][j+2]=='c'&&string[i][j+3]=='u'&&string[i][j+4]=='r'&&string[i][j+5]=='e')){
					virus++;
					printf("%s\n", string[i]);
					break;
				}
			}	
		}
	}
	if(virus<4)	printf("safe");
	else if(virus<7) printf("warning");
	else printf("danger");
}
