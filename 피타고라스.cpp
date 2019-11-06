#include<stdio.h>
#include<math.h>
int main(){
	long long int n;
	long long int output=0;
	long long int a, b;
	scanf("%lld", &n);
	for(long long int i=1;i<n;i++){
		if((n*n)%i==0){
			a=i;
			b=(n*n)/i;
			if((a+b)%2==0&&((a+b)/2)*((a+b)/2)==((b-a)/2)*((b-a)/2)+n*n&&(b-a)/2>n)
				output++;
		}
	}
	printf("%lld", output);
}
