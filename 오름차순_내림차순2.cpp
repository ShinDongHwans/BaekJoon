
#include <stdio.h>
#include <string.h>

int data[100];
int n;

int bigger(int k){
	if(k>=n-1){
		printf("¿À¸§Â÷¼ø");
		return 0;
	}
	if(data[k]<=data[k+1]) 
		return bigger(k+1);
	else{
		printf("¼¯ÀÓ");
		return 0;
	}
}

int smaller(int k){
	if(k>=n-1){
		printf("³»¸²Â÷¼ø");
		return 0;
	}
	if(data[k]>=data[k+1]) 
		return smaller(k+1);
	else{
		printf("¼¯ÀÓ");
		return 0;
	}
}

int check(int k){
	if(k>=n-1){
		return 0;
	}
	if(data[k]==data[k+1]) 
		return check(k+1);
	else{
		if(data[k]>data[k+1])
			return 1;
		else
			return 2;
	}
}


int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &data[i]);
		
	if(data[0]>data[1])
		smaller(0);
	else if(data[0]==data[1]){
		int c=check(0);
		if(c==1)
			smaller(0);
		else if(c==2)
			bigger(0);
		else
			printf("¼¯ÀÓ");
	}
	else	
		bigger(0);
}
