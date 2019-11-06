#include<stdio.h>
#include<string.h>

int n;
int months[100];
int days[100];
char name[100][55];
char month[100][25];
char day[100][20];

void check_month(){
	for(int i=0;i<n;i++){
		if(!strcmp(month[i], "January"))
			months[i]=1;
		else if(!strcmp(month[i], "February"))
			months[i]=2;
		else if(!strcmp(month[i], "March"))
			months[i]=3;
		else if(!strcmp(month[i], "April"))
			months[i]=4;
		else if(!strcmp(month[i], "May"))
			months[i]=5;
		else if(!strcmp(month[i], "June"))
			months[i]=6;
		else if(!strcmp(month[i], "July"))
			months[i]=7;
		else if(!strcmp(month[i], "August"))
			months[i]=8;
		else if(!strcmp(month[i], "September"))
			months[i]=9;
		else if(!strcmp(month[i], "October"))
			months[i]=10;
		else if(!strcmp(month[i], "November"))
			months[i]=11;
		else if(!strcmp(month[i], "December"))
			months[i]=12;
	}
}

void check_day(){
	for(int i=0;i<n;i++){
		for(int j=0;day[i][j]!='s'&&day[i][j]!='t'&&day[i][j]!='n'&&day[i][j]!='r';j++){
			days[i]*=10;
			days[i]+=day[i][j]-48;
		}
	}
}

int check(){
	int output=0;
	check_month();
	check_day();
	for(int i=0;i<n-1;i++){
		if(months[i]>months[i+1])
			output++;
		else if(months[i]==months[i+1]){
			if(days[i]>days[i+1])
				output++;
		}
	}
	return output;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s %s %s", name[i], month[i], day[i]);
	}
	if(check()==1)
		printf("%s is 1 year older than %s.", name[0], name[n-1]);
	else if(check()==0)
		printf("No difference");
	else
		printf("%s is %d years older than %s.", name[0], check(), name[n-1]);
}
