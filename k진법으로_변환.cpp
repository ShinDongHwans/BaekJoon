#include <stdio.h>
char day[8][10]={"Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday", "Sunday"};

int tobin( int y, int m, int d ){
    int output=y*365+y/4-y/100+y/400+(d-1);
	if(m<8){
    	output+=(m+1)/2*31+m/2*30;
	}
	else if(m==8)
		output+=245;
	else{
		output+=245;
		m-=8;
		output+=(m+1)/2*30+m/2*31;
	}
	return output;
}
  
int main()
{
    int n, y, m, d;
    int x; 
    scanf( "%d %d %d %d", &n, &y, &m, &d);
    printf("\"Mathemagic!\"\n");
    printf("%d\n", n*n);
    x=tobin(y-1, m-1, d);
	printf("%d %s", x, day[x%7]);
}
