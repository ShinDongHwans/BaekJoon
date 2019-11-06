#include<stdio.h>
int num[150];
int remain[1000];
int n, k;
int check(int x){
	if(num[x]==0)
		return 1;
	int obj = num[x]%k;
	if(remain[obj]>0)
		return 0;
	else
		remain[obj]++;
	return check(x+1);
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &num[i]);
	scanf("%d", &k);
	if(check(0))
		printf("yes");
	else
		printf("no");
}
