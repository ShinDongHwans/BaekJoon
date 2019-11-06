#include<stdio.h>
long long int fibo[100]={0, 1, 0, };
long long int fibo_0[100]={1, 0,};
long long int fibo_1[100]={0, 1, 0,};

long long int f(int n){
	if(n==0)
		return 0;
    if(fibo[n]!=0){
        return fibo[n];
	}
    else if(fibo[n-1]!=0&&fibo[n-2]!=0){
        return fibo[n-1]+fibo[n-2];
    }
    else{
        fibo[n-1]=f(n-1);
        fibo[n-2]=f(n-2);
        fibo_0[n]=fibo_0[n-1]+fibo_0[n-2];
        fibo_1[n]=fibo_1[n-1]+fibo_1[n-2];
        return f(n-1)+f(n-2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
    	long long int a;
    	scanf("%lld", &a);
    	f(a);
    	printf("%lld %lld\n", fibo_0[a], fibo_1[a]);
	}
}
