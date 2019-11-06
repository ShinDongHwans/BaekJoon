#include<stdio.h>
#include<math.h>

long long int find(long long int a, int x){
	int l=0;
	int output=a;
	for(l;a>0;l++){
		a/=10;
	}
	for(int i=l-1;i>=0;i--){
		output+=7*pow(10,i);
		if(output%x==0)
			return output;
		for(int j=0;j<i;j++){
			output+=7*pow(10,j);
			if(output%x==0)
				return output;
		}
		output-=7*pow(10,i);
	}
	return output;
}

int main(){
	int n;
	long long int out=7; 
	scanf("%d", &n);
	while(out%n!=0){
		out=find(out*10, n);
	}
	printf("%lld", out);
}
