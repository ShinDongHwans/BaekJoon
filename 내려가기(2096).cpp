#include<stdio.h>

int input[3];
int dpmax1[3];
int dpmax2[3];
int dpmin1[3];
int dpmin2[3];

int max(int a, int b){
	return a>b ? a:b;
}

int min(int a, int b){
	return a>b ? b:a;
}

int main(){
	int n, i, max1, max2, min1, min2;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		if(i%2==1){
			max1 = max(dpmax1[0], dpmax1[1]);
			max2 = max(dpmax1[1], dpmax1[2]);
			min1 = min(dpmin1[0], dpmin1[1]);
			min2 = min(dpmin1[1], dpmin1[2]);
			dpmax2[0] = max1+input[0];
			dpmax2[1] = max(max1, max2)+input[1];
			dpmax2[2] = max2+input[2];
			dpmin2[0] = min1+input[0];
			dpmin2[1] = min(min1, min2)+input[1];
			dpmin2[2] = min2+input[2];
		}
		else{
			max1 = max(dpmax2[0], dpmax2[1]);
			max2 = max(dpmax2[1], dpmax2[2]);
			min1 = min(dpmin2[0], dpmin2[1]);
			min2 = min(dpmin2[1], dpmin2[2]);
			dpmax1[0] = max1+input[0];
			dpmax1[1] = max(max1, max2)+input[1];
			dpmax1[2] = max2+input[2];
			dpmin1[0] = min1+input[0];
			dpmin1[1] = min(min1, min2)+input[1];
			dpmin1[2] = min2+input[2];
		}
		
	}
	if(n%2==1)
		printf("%d %d", max(max(dpmax2[0], dpmax2[1]), dpmax2[2]), min(min(dpmin2[0], dpmin2[1]), dpmin2[2]));
	else
		printf("%d %d", max(max(dpmax1[0], dpmax1[1]), dpmax1[2]), min(min(dpmin1[0], dpmin1[1]), dpmin1[2]));
}
