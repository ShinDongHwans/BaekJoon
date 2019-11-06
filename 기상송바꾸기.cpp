#include<stdio.h>
int main(){
	int n;
	char song[100];
	scanf("%d", &n);
	for(int i=0;i<=n;i++){
		gets(song);
		if(i!=0)
			printf("%s\n", song);
		if(i==n)
			break;
		else if(i!=0)
			printf("AMOLED\n");
	}
}
