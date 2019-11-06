#include <stdio.h>
#include <math.h>
int main(){
	int a, b, c;
	int D;
	scanf("%d %d %d", &a, &b, &c);
	D=b*b-4*a*c;
	if(D==0)
		printf("%.2f", (float)-b/2/a);
	else if(D>0)
		printf("%.2f\n%.2f", (-b+sqrt(D))/2/a, (-b-sqrt(D))/2/a);
	else{
		if(a<0)
			printf("%.2f+%.2fi\n%.2f%.2fi",(float)-b/(2*a) , -sqrt(-D)/2/a,(float)-b/2/a , sqrt(-D)/2/a);
		else
			printf("%.2f+%.2fi\n%.2f-%.2fi",(float)-b/(2*a) , sqrt(-D)/2/a,(float)-b/2/a , sqrt(-D)/2/a);
	}
	
}
