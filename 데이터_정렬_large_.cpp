#include <stdio.h>
int main(){
	int n;
	int num;
	int exist[100000]={};
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &num);
		exist[num]++;
	}
	for(int i=0;i<100000;i++){
		for(int j=0;j<exist[i];j++)
			printf("%d ", i);
	}
}
