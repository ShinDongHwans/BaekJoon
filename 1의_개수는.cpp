#include <stdio.h>
 
int main()
{
	int s, f;
	int output=0;
	int n1, n2, n3, n4, n5, n6, n7;
	scanf("%d %d", &s, &f);
	for(int j=s;j<f+1;j++){
		n1=j/1000000;
		n2=(j%1000000)/100000;
		n3=(j%100000)/10000;
		n4=(j%10000)/1000;
		n5=(j%1000)/100;
		n6=(j%100)/10;
		n7=j%10;
		n1=n1==1?1:0;
		n2=n2==1?1:0;
		n3=n3==1?1:0;
		n4=n4==1?1:0;
		n5=n5==1?1:0;
		n6=n6==1?1:0;
		n7=n7==1?1:0;
		output+=n1+n2+n3+n4+n5+n6+n7;
	}
	printf("%d", output);
}
