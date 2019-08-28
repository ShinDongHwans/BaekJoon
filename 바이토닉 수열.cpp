#include<stdio.h>
int n;
int numList[1000];
int dpup[1000];
int dpdown[1000];
int max=0;

void bitonic(int index){
	if(index == n) return;
	else{
		int i, maxdp=0;
		for(i=0;i<n;i++){
			if(numList[index]>numList[i]){
				if(maxdp < dpup[i]) maxdp = dpup[i];
			}
		}
		dpup[index]=maxdp+1;
		return bitonic(index+1);
	}
}

void bitonicdown(int index){
	if(index == -1) return;
	else{
		int i, maxdp=0;
		for(i=n-1;i>=0;i--){
			if(numList[index]>numList[i]){
				if(maxdp < dpdown[i]) maxdp = dpdown[i];
			}
		}
		dpdown[index]=maxdp+1;
		return bitonicdown(index-1);
	}
}

int findMax(int n){
	int i,sub, output=0;
	for(i=0;i<n;i++){
		sub=dpup[i]+dpdown[i];
		if(output < sub) output=sub;
	}
	return output-1;
}

int main(){
	int i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &numList[n-1-i]);
	bitonic(0);
	bitonicdown(n-1);
	
	printf("%d", findMax(n));
} 
