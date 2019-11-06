#include <stdio.h>
int array[50000];
int k=0;
void tobin( int x, int y )
{
    if( x / y )
        tobin(x/y, y);
    array[k]=x%y;
    k++;
}

int main(){
	int n;
	scanf("%x", &n);
	tobin(n, 2);
	for(int i=0;i<4-(k%4);i++)
		printf("0");
	for(int i=0;i<k;i++){
		if((k-i)%4==0&&i!=0)
			printf(" ");
		printf("%d", array[i]);
	}
}
