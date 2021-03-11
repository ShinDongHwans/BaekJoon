#include<stdio.h>
int main(){
	int T, a, b, money;
	int numA[] ={1, 3, 6, 10, 15, 21};
	int numB[] ={1, 3, 7, 15, 31};
	int priceA[] ={500, 300, 200, 50, 30, 10};
	int priceB[] ={512, 256, 128, 64, 32}; 
	scanf("%d", &T);
	while(T-->0){
		money=0;
		scanf("%d %d", &a, &b);
		if(a!=0){
			for(int i=0;i<6;i++){
				if(a <= numA[i]){
					money+=priceA[i];
					break;
				}
			}
		}
		if(b!=0){
			for(int i=0;i<5;i++){
				if(b <= numB[i]){
					money+=priceB[i];
					break;
				}
			}
		}
		printf("%d\n", money*10000);
	}
}
