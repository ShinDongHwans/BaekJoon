#include <stdio.h>
char day[8][10]={"Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int date[6][7];

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

void start(int x, int y){
	for(int i=0;i<y;i++){
		date[(x+i)/7][(x+i)%7]=1+i;
	}
}


void make(int y, int m, int x){
	int j;
	printf("CALENDAR %d %d\n", y, m);
	printf("   S   M   T   W   T   F   S\n");
	if(m==2){
		if(y%4==0&&(y%100!=0||y%400==0)){
			start(x, 29);
		}
		else
			start(x, 28);
	}
	else if(m%2==1&&m<8)
		start(x, 31);
	else if(m%2==0&&m<8)
		start(x, 30);
	else if(m%2==0)
		start(x, 31);
	else start(x, 30);
	for(int i=0;i<6;i++){
		if((i==5||i==6)&&date[i][0]==0)
			break;
		for(j=0;j<7;j++){
			if(date[i][j]==0)
				printf("    ");
			else{
				if(date[i][j]/10)			
					printf("  %d", date[i][j]);
				else
					printf("   %d", date[i][j]);
				if(j<6&&date[i][j+1]==0)
					break;
			}
		}
		printf("\n");
	}
	if(tobin(y-1, m-1, 12)%7==4)
		printf("Oh my god!");
	else
		printf("%s", day[tobin(y-1, m-1, 12)%7]);
}
	  
int main()
{
	int x;
    int y, m;
    scanf("%d %d", &y, &m);
    x=tobin(y-1, m-1, 0)%7;
    make(y, m, (x+1)%7);
}
