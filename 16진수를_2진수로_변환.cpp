#include <stdio.h>
#include <string.h>
char array[50000];


void toxen(char arr[], int n){
	int x;
	if(n==strlen(array))
		return;
	if(arr[n]<60)
		x=arr[n]-48;
	else
		x=arr[n]-55;
	switch(x){
		case 0:
			printf("0000");
			break;
		case 1:
			printf("0001");
			break;
		case 2:
			printf("0010");
			break;
		case 3:
			printf("0011");
			break;
		case 4:
			printf("0100");
			break;
		case 5:
			printf("0101");
			break;
		case 6:
			printf("0110");
			break;
		case 7:
			printf("0111");
			break;
		case 8:
			printf("1000");
			break;
		case 9:
			printf("1001");
			break;
		case 10:
			printf("1010");
			break;
		case 11:
			printf("1011");
			break;
		case 12:
			printf("1100");
			break;
		case 13:
			printf("1101");
			break;
		case 14:
			printf("1110");
			break;
		case 15:
			printf("1111");
			break;
		
	}
	printf(" ");
	toxen(arr, n+1);
}

int main(){
	scanf("%s", &array);
	toxen(array, 0);
}
