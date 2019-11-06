#include <stdio.h>
int prime[10000]={2, 3, 5, 7};
int factor[10000];
int n;
int e=4;

int check(){
	int output = 1;
	for(int i=0;i<100;i++){
		output*=(factor[i]+1);
		factor[i]=0;
	}
	if(output>n)
		return 1;
	else
		return 0;
}

int tobin(int x){
	int num=x*(x+1)/2;
	for(int i=0;prime[i]!=0;i++){
		while(num%prime[i]==0){
			num/=prime[i];
			factor[i]++;
		}
	}
	
	if(num!=1){
		prime[e]=num;
		factor[e]++;
		e++;
	}
		
	if(check())
		return x*(x+1)/2;
	return tobin(x+1);
}

int main(){
	scanf("%d", &n);
	printf("%d", tobin(1));
}
