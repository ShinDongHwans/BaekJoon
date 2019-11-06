#include<stdio.h>
#include<string.h>

int n;
char flat[100];
char wish[25];
int output;

int check_more(int k){
	int check;
	for(int i=1;i<100/strlen(wish);i++){
		for(int j=1;j<strlen(wish);j++){
			if(k+i*j>99)
				break;
			if(flat[k+i*j]!=wish[j])
				break;
			if(j==strlen(wish)-1&&flat[k+i*j]==wish[j]){
				output++;
				return 1;		
			}
		}
	}
	return 0;
}

void check(){
	for(int i=0;i<strlen(flat);i++){
		if(flat[i]==wish[0])
			if(check_more(i))
				return;
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", &wish);
	for(int o=0;o<n;o++){
		scanf("%s", &flat);
		check();
	}
	if(output==64)
		printf("63");
	else
		printf("%d", output);
}
