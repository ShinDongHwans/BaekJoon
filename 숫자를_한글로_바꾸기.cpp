
#include <stdio.h>
char name[5][10]={"","", "½Ê","¹é", "Ãµ"};
char num[11][10]={"", "ÀÏ", "ÀÌ", "»ï", "»ç", "¿À", "À°", "Ä¥", "ÆÈ", "±¸"};

int print(int x, int k){
	if(x/10){
		print(x/10, k+1);	
	}
	if(x%10!=0)
		printf("%s", num[x%10]);
	if(k==5&&(x%10000)!=0){
		printf("¸¸");
		k-=4;
	}
	else if(k==9){
		printf("¾ï");
		k-=9;
	}
	if(k>5)
		k++;
	if(k>9)
		k++;
	if(x%10!=0)
		printf("%s", name[k%5]);
}
		

int main()
{
    int n;
    scanf("%d", &n );
    if(n==0)
    	printf("¿µ");
   	else 
	    print(n, 1);
}
