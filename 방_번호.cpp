#include<stdio.h>

int f(int n){
	int num[9]={};
	int max=1;
	while(n>0){
		if(n%10==9)
			num[6]++;
		else
			num[n%10]++;
		n/=10;
	}
	num[6]=(num[6]+1)/2; 
	for(int i=0;i<9;i++){
		if(max<num[i])
			max=num[i];
	}
	return max;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
}
