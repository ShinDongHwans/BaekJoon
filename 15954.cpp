#include<stdio.h>
#include<stdio.h>

double std(int a, int b, int c){
	double mean = (a+b+c)/3;
	return sqrt(pow(a-mean, 2)+pow(b-mean,2)+pow(c-mean,2));
}

int main(){
	int n, k;
	double output=10000000000;
	scanf("%d %d", &n, &k);
	int input[n];
	if(n==1) printf("0");
	scanf("%d %d", &input[0], &input[1]);
	for(int i=2;i<n;i++){
		scanf("%d", &input[i]);
		double new_std = std(input[i-2], input[i-1], input[i]);
		output = output > new_std ? output : new_std;
	}
}
