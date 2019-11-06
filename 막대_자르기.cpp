#include<stdio.h>
int main(){
	int i=0;
	char s[9];
	for(int i=0;i<8;i++){
		scanf("%s", &s);
		for(int j=0;j<8;j++){
			if(i%2==0&&j%2==0&&s[j]=='F')
				i++;
		}
	}
	printf("%d", i);
}
