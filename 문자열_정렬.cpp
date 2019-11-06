#include<stdio.h>
#include<string.h>
#include<math.h>

char string[10000][11];
int location[10000][10];
int value[10];


void sort(int n){
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<strlen(string[j]);j++){
			value[j]=string[i][j]%96;
			sum+=value[j]*pow(10, 10-j);
		}
		for(int j=0;j<10;j++){
			location[sum][j]=value[j];
		}
	}
}

void print(){
	for(int i=1;i<13663;i++){
		if(location[i][0]!=0){
			for(int j=0;j<10;j++){
				if(location[i][j]!=0){
					printf("%c", location[i][j]+96);
				}
			}
			printf("\n");
		}
	}
}

int main(){
	int num;
	scanf("%d", &num);
	for(int i=0;i<num;i++){
		scanf("%s", string[i]);
	}
	sort(num);
	print();
}
