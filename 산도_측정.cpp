#include <stdio.h>
#include <string.h>
int pol[1001]; 

int main()
{
	int n, x;
	int max1=0, pol1;
	int max2=0, pol2;
	int output1, output2;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		pol[x]++;
	}
	for(int i=1;i<1001;i++){
		if(max1<pol[i]){
			max1=pol[i];
			pol1=i;
		}
	}
	
	for(int i=1000;i>0;i--){
		if(max2<pol[i]&&pol1!=i){
			max2=pol[i];
			pol2=i;
		}	
	}
	output1=pol1-pol2>0?pol1-pol2:pol2-pol1;
	
	max1=0;
	max2=0;
	for(int i=1000;i>0;i--){
		if(max1<pol[i]){
			max1=pol[i];
			pol1=i;
		}
	}
	
	for(int i=1;i<1001;i++){
		if(max2<pol[i]&&pol1!=i){
			max2=pol[i];
			pol2=i;
		}	
	}
	output2=pol1-pol2>0?pol1-pol2:pol2-pol1;
	
	if(output1>output2)
		printf("%d", output1);
	else
		printf("%d", output2);
}
