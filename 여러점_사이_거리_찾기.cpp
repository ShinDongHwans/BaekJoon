#include <stdio.h>
#include <math.h>
 
double distance(double a, double b, double c, double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main(){
	double xy[100][2];
	int n;
	double output=0;
	
	scanf("%d", &n);
	scanf("%lf %lf", &xy[0][0], &xy[0][1]);
	for(int i=1;i<n;i++){
		scanf("%lf %lf", &xy[i][0], &xy[i][1]);
		output+=distance(xy[i][0], xy[i][1], xy[i-1][0], xy[i-1][1]);
	}
	printf("%.2lf", output);
	
}
