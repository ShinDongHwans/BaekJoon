#include <stdio.h>
#include <string.h>
int main(){
	char name[1000]={};
	int n;
	scanf("%d", &n);
	for(int j=0;j<n;j++){
		scanf("%s", &name);
		for(int i = strlen(name)-1;i>=0;i--)
			printf("%c", name[i]);
		printf("\n");
	}
}
