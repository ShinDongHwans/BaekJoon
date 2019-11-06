#include<stdio.h>
#include<string.h>
char base[1000];
char obj[1000];
int basic[1000];
int object[1000];
int lb;
int lo;

void find(char str[], int loc[], int k){
	int g=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='/'){
			loc[g]=i;
			if(k==0)
				lb++;
			else
				lo++;
			g++;
		}
	}
	loc[g]=strlen(str);
}

void print(int a){
	if(a==lb-1)
		printf("./");
	else{
		for(int i=0;i<=lb-a-2;i++)
			printf("../");
	}
	for(int i=object[a]+1;i<strlen(obj);i++)
		printf("%c", obj[i]);
}

int main(){
	int x=0;
	scanf("%s", &base);
	scanf("%s", &obj);
	find(base, basic, 0);
	find(obj, object, 1);
	while((object[x]!=0||x==0)){
		for(int i=object[x];i<object[x+1];i++){
			if(base[i]!=obj[i]){
				print(x);
				return 0;
			}
		}
		x++;
	}
}
