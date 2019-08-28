#include<stdio.h>

int saver[100001] = {0, 1, 2, 3, 1};

int min(int x, int y){
	if(x<y) return x;
	return y;
} 

int root(int n){
	if(n<0) return -1;
	int output = 0;
	while(output*output <= n)
		output++;
	return output-1;
}

int calculate(int index, int n){
	if(index > n) return saver[n];
	else if(index==0) return 0;
	else if(saver[index]!=0) return saver[index];
	else{
		int k=root(index);
		int i=2;
		saver[index] = index;
		for(i;i<=k;i++)
			saver[index] = min(saver[index], calculate(index-i*i, n)+1);
		return calculate(index+1, n);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", calculate(5, n));
	return 0;
}
