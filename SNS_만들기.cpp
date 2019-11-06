
#include<stdio.h>
#include<string.h>
char user[150][1000];
int female, male;
int num;

void scan(int n){
	for(int i=0;i<n;i++)
		scanf("%s", &user[i]);
}

int check_sex(int n){
	int output=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(user[i]);j++){
			if(user[i][j]==','){
				if(user[i][j+1]=='M')
					output++;
				break;
			}
		}
	}
	return output;
}

int anal_age(int who, int start, int len){
	int age=0;
	for(int i=1;i<=len;i++){
		age*=10;
		age+=(user[who][start+i]-48);
	}
	return age;
}

double check_age(int n){
	double output=0;
	int count=0;
	for(int i=0;i<num;i++){
		for(int j=0;j<strlen(user[i]);j++){
			if(user[i][j]==','){
				count++;
				if(count==2){
					if(user[i][j+2]==',')
						output+=anal_age(i, j+3, 1);
					else if(user[i][j+3]==',')
						output+=anal_age(i, j+3, 2);
					else if(user[i][j+4]==',')
						output+=anal_age(i, j+3, 3);
					count=0;
					break;
				}
			}
		}
	}
	output/=n;
	return output;
}

double check_friend(int n){
	double output=0;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(user[i]);j++){
			if(user[i][j]==','){
				count++;
			}
		}
		output+=count-2;
		count=0;
	}
	output/=n;
	return output;
}

int find_age(char na[]){
	int output;
	for(int i=0;i<num;i++){
		for(int j=0;j<strlen(na);j++){
			if(na[j]!=user[i][j])
				break;
			if(j==strlen(na)-1&&na[j]==user[i][j]){
				if(user[i][j+5]==',')
					output=anal_age(i, j+3, 1);
				else if(user[i][j+6]==',')
					output=anal_age(i, j+3, 2);
				else if(user[i][j+7]==',')
					output=anal_age(i, j+3, 3);
				return output;
			}
		}
	}
}

void show_friend(char na[]){
	int output;
	for(int i=0;i<num;i++){
		for(int j=0;j<strlen(na);j++){
			if(na[j]!=user[i][j])
				break;
			if(j==strlen(na)-1&&na[j]==user[i][j]){
				int count=0;
				for(int k=1;;k++){
					if(user[i][j+k]=0)
						return;
					if(count==3){
						if(user[i][j+k]!=',')
							printf("%c", user[i][j+k]);
						else
							printf("\n");
					}
					else if(user[i][j+k]==',')
						count++;
				}
			}
		}
	}
}

int main(){
	char find[10];
	scanf("%d", &num);
	scan(num);
	scanf("%s", &find);
	show_friend(find);
}
