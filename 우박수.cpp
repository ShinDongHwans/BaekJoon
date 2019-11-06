#include <stdio.h>
int array[1000]={};

int snow(int n, int i){
	if(n==1){
		array[i]=1;
		i++;
		return i;
	}
	if(n%2==0){
		array[i]=n;
		i++;
		return snow(n/2, i);
	}
	else{
		array[i]=n;
		i++;
		return snow(3*n+1, i);
	}
}

int main(){
	int a, b;
	int output1=0;
	int output2=0;
	int len;
	scanf("%d %d", &a, &b);
	for(int i=a; i<=b; i++){
		array[1000]={};
		len = snow(i, 0);
		if(len > output2){
			output1 =i;
			output2 = len;
		}
	}
	printf("%d %d", output1, output2);
}
