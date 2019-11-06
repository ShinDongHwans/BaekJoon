#include<stdio.h>
#include<math.h>

int big1;
int big2;

int compare(int n1, int n2){
	if(big1>n1&&big2>n2)
		return 0;
	else if(big1<n1&&big2<n2){
		big1=n1;
		big2=n2;
		return 1;
	}
	else{
		if(pow(n1, (double)n2/big2)>big1){
			big1=n1;
			big2=n2;
			return 1;
		}
		else
			return 0;	
	}
}

int main(){
	int n;
	int output;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		if(compare(num1, num2))
			output=i+1;
	}
	
	printf("%d", output);
}
