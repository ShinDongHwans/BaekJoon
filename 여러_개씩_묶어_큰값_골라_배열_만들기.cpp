#include <stdio.h>

int min(int x, int y){
	if(x>y)
		return x;
	else
		return y;
}

int main(){
	int n, g;
	int m[100]={};
	int minor;
	int range;
	scanf("%d %d", &n, &g);
	for(int i=0;i<n;i++){
		scanf("%d", &m[i]);
	}
	if(n%g!=0)
		range = n/g+1;
	else
		range = n/g;
	for(int i=0;i<range;i++){
		minor=-1000;
		for(int j=i*g;j<i*g+g&&j<n;j++){
			minor=min(minor,m[j]);
		}
		m[i]=minor;
	}
	
	for(int i=0;i<range;i++){
		printf("%d ", m[i]);
	}
}
