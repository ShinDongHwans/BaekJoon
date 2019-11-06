#include<stdio.h>
char num[501];

void sort(){
	for(int i=499;i>=0;i--){
		if(num[i]==0)
			break;
		if(num[i]-48>990){
			if(num[i-3]==0)
				num[i-3]=(num[i]-48)/1000+48;
			else
				num[i-3]+=(num[i]-48)/1000;
			num[i]=(num[i]-48)%1000+48;
		}
		if(num[i]-48>99){
			if(num[i-2]==0)
				num[i-2]=(num[i]-48)/100+48;
			else
				num[i-2]+=(num[i]-48)/100;
			num[i]=(num[i]-48)%100+48;
		}
		if(num[i]-48>9){
			if(num[i-1]==0)
				num[i-1]=(num[i]-48)/10+48;
			else
				num[i-1]+=(num[i]-48)/10;
			num[i]=(num[i]-48)%10+48;
		}
	}
}

void set(int loc, int value, int check){
	if(num[loc]==0)
		num[loc]=value+48;
	else{
		if(check==1)
			num[loc]+=value;
		else
			num[loc]=value+48;
	}
}

void factorization(int start, int end){
	if(start==1){
		num[499]='1';
		if(end==1)
			return;
		else
			return factorization(2, end);
	}
	
	for(int i=0;i<500;i++){
		if(num[i]==0)
			continue;
		int cal=(num[i]-48)*start;
		if(cal>999){
			set(i-3, cal/1000, 1);
			set(i-2, cal%1000/100, 1);
			set(i-1, cal%100/10, 1);
			set(i, cal%10, 0);
		}
		else if(cal>99){
			set(i-2, cal/100, 1);
			set(i-1, cal%100/10, 1);
			set(i, cal%10, 0);
		}
		else if(cal>9){
			set(i-1, cal/10, 1);
			set(i, cal%10, 0);
		}
		else
			set(i, cal, 0);
	}
	
	sort();
	
	if(start==end)
		return;
	return factorization(start+1, end);
}

void print1(){
	for(int i=0;i<500;i++){
		if(num[i]!=0)
			printf("%c", num[i]);
	}
	printf("\n");
} 


void print2(){
	for(int i=0;i<500;i++){
		if(num[i]!=0){
			printf("%d", 500-i);
			return;
		}
	}
} 

void print3(){
	for(int i=499;i>=0;i--){
		if(num[i]!='0'){
			printf("%c", num[i]);
			return;	
		}
	}
}

void reset(){
	for(int i=0;i<500;i++)
		num[i]=0;
}

int main(){
	int n;
	scanf("%d", &n);
	factorization(1, n);
	print3();
}
