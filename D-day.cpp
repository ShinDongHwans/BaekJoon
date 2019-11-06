
	#include <stdio.h>
	
	int tobin( int y, int m, int d ){
	    int output=y*365+y/4-y/100+y/400+d;
	    if(m==1)
	    	output+=31;
		else if(m>1&&m<8){
			m-=2;
			output+=59;
	    	output+=(m+1)/2*31+m/2*30;
	    	m+=2;
		}
		else if(m==8)
			output+=243;
		else if(m!=0){
			output+=243;
			m-=8;
			output+=(m+1)/2*30+m/2*31;
			m+=8;
		}
		if((y+1)%4==0&&((y+1)%100!=0||(y+1)%400==0)&&m>1){
			output++;	
		}
		return output;
	}
	  
	int main()
	{
	    int ny, m, d;
	    int x; 
	    int y;
	    scanf("%d %d %d", &y, &m, &d);
	    x=tobin(y-1, m-1, d-1);
	    scanf("%d %d %d", &y, &m, &d);
	    y=tobin(y-1, m-1, d-1);
	    if(y>x)
	    	printf("D+%d", y-x);
	    else
	    	printf("D-%d", x-y);
	}
