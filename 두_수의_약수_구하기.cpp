#include <stdio.h>
#include <math.h>
int output[2048];
int i=0;

int rearrange(int i){
	if(output[i]==0)
		return 0;
	if(output[i]==output[i+1])
		output[i]=0;
	return rearrange(i+1);
}

int find(int x){
	for(int i=0;i<2048;i++){
		if(x<=output[i]||output[i]==0)
			return i;
	}
}

int put (int x){
	int c=find(x);
	for(int i=2047;i>c;i--){
		output[i]=output[i-1];
	}
	output[c]=x;
}

int find(int a, int b, int k){
	if(k>sqrt(b))
		return 0;
	if(b%k==0&&a%k==0){
		output[i]=k;
		i++;
		find(a, b, k+1);
		output[i]=b/k;
		i++;
		put(a/k);
		i++;
	}
	else if(b%k==0){
		output[i]=k;
		i++;
		find(a, b, k+1);
		output[i]=b/k;
		i++;
	}
	else if(a%k==0){
		output[i]=k;
		i++;
		find(a, b, k+1);
		put(a/k);
		i++;
	}
	else
		find(a, b, k+1);
}
	

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	if(x>y){
		int c=y;
		y=x;
		x=c;
	}
	find(x, y, 1);
	rearrange(0);
	for(int i=0;i<2047;i++){
		if(output[i]!=0)
			printf("%d ", output[i]);
	}
}
