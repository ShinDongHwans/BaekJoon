#include<stdio.h>
int main(){
	int array[10][10]={};
	int w1, w2;
	int l1, l2;
	int b1, b2;
	int b3, b4;
	int i,j;
	int sight=0;
	
	
	scanf("%d %d", &w1, &w2);
	scanf("%d %d", &l1, &l2);
	scanf("%d %d", &b1, &b2);
	scanf("%d %d", &b3, &b4);
	for(i=b1; i<=b3; i++){
		for(j=b2; j<=b4; j++)
			array[i][j]=3;
	} //부시 범위
	 
	
	for(i=l1-2;i<=l1+2;i++){
		for(j=l2-2;j<=l2+2;j++){
			if(i>0&&i<10&&j>0&&j<10)
				array[i][j] = 'b';
		}
	}// 렌즈 범위
	 
	if((l1-2<=w1 && l1+2>=w1)&&(l2-2<=w2&&l2+2>=w2)){
		printf("0");
		return 0;
	}// 와드가 렌즈 범위안에 있으면 gg 
	
	if((b1<=w1 && b3>=w1)&&(b2<=w2&&b4>=w2)){
		for(i=b1; i<=b3; i++){
			for(j=b2; j<=b4; j++){
				if(array[i][j]==3)
					array[i][j]=2;
			}
		}
	}// 와드가 부쉬안에 있으면 
	
	for(i=w1-2;i<=w1+2;i++){
		for(j=w2-2;j<=w2+2;j++){
			if(i>0&&i<10&&j>0&&j<10){
				if(array[i][j]==0)
					array[i][j]=2; 
			}
		}
	}
	
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			if(array[i][j]==2)
				sight++;
		}
	}
	
	printf("%d", sight);
} 
