#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
int abs(int x){return x>0 ? x:-x;}

int max(int a, int b){return a>b ? a:b;}

int min(int a, int b){return a<b ? a:b;}

int root(int n){
	int output = 1;
	while(output*output <= n)
		output++;
	return output-1;
}

int log(int n, int x){
	if(x==0) return 0;
	int compare = 1;
	int output = 0;
	while(compare <= x){
		compare*=n;
		output++;
	}
	return output-1;
}

int pow(int x, int n){
	int output = 1;
	while(n-->0)
		output*=x;
	return output;
}

long long int div_up(long int n, long int m){
	if(n%m!=0) return n/m+1;
	else return n/m;
}

int reverse(int n){
	int length = log(10, n)+1;
	int output=0;
	while(length>0){
		output*=10;
		output+=n%10;
		n/=10;
		length--;
	}
	return output;
}

int count(int x, int n){
	if(n==1) return 1;
	int over = 1;
	int output=0;
	while(x >= pow(n, over)){
		output+=x/pow(n, over);
		over++;
	}
	return output;
}

long long int fac(int n){
	long long int output = 1;
	while(n>0){
		output*=n;
		n--;
	}
	return output;
}

long long int nCr(long long int n, long long int r){
	long long int output = 1;
	long long int bigger = max(r, n-r);
	long long int multi = n;
	long long int divis = 1;
	while(multi >bigger){
		output*=multi;
		output/=divis;
		multi--;
		divis++;
	}
	return output;
}


//submit
void prob1712(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(b < c)
		printf("%d", a/(c-b)+1);
	else 
		printf("-1");
	return;
}

//submit
void prob2914(){
	int a, i;
	scanf("%d %d", &a, &i);
	printf("%d", a * (i-1)+1);
	return;
}

//submit
void prob1107(){
	//Initializing Step
	int channel, num, button[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	scanf("%d %d", &channel, &num);
	for(int i=0;i<num;i++){
		int x;
		scanf("%d", &x);
		button[x] = -1;
	}
	//If all buttons are wrong, we just move + -
	int onlypm = abs(channel - 100);
	if(num == 10){
		printf("%d", onlypm);
		return;
	}
	else{
		int x = channel;
		int buttonlist = 0;
		int length = log(10, x) + 1;
		while(length-->0){
			int digit = x/pow(10, length);
			if(button[digit]==digit){
				buttonlist = buttonlist*10+digit;
				x=x%pow(10, length);
			}
			else{
				int maxv=-1, minv=10, nzerominv=10;
				int bigger=10, smaller = -1;
				int hubo[6]={-1,-1,-1,-1,-1,-1};
				int i=-1, c;
				while(i++<10){
					c = button[i];
					if(c==i){
						maxv = max(maxv, i);
						minv = min(minv, i);
						if(nzerominv == 10 && i!=0)
							nzerominv = min(nzerominv, i);
					}
				}
				i=0;
				while(i<digit){
					if(button[i]==i)
						smaller = max(smaller, i);
					i++;
				}
				i=digit+1;
				while(i<10){
					if(button[i]==i)
						bigger = min(bigger, i);
					i++;
				}
				if(length != log(10, channel) && buttonlist > 0){
					hubo[2] = buttonlist;
					hubo[3] = buttonlist;
					int copy, l, count, sub;
					while(hubo[2]-- && hubo[2] >=0){
						copy = hubo[2];
						count=0;
						l = log(10, copy)+1;
						while(l-->0){
							sub = pow(10, l);
							if(button[copy/sub] == copy/sub) count++;
							copy = copy%sub;
						}
						if(count == log(10, hubo[2])+1)
							break;
					}
					while(hubo[3]++ && hubo[3] <= channel+onlypm){
						copy = hubo[3];
						count=0;
						l = log(10, copy)+1;
						while(l-->0){
							sub = pow(10, l);
							if(button[copy/sub] == copy/sub) count++;
							copy = copy%sub;
						}
						if(count == log(10, hubo[3])+1)
							break;
					}					
					for(i=0;i<length+1;i++){
						hubo[2] = hubo[2]*10 + maxv;
						hubo[3] = hubo[3]*10 + minv;
					}
				}
				
				hubo[4] = 0;
				hubo[5] = nzerominv;
				if(channel < 10){
					hubo[4] = hubo[4]*10 + maxv;
					hubo[5] = hubo[5]*10 + minv;
				}
				else{
					for(i=0;i<log(10, channel);i++){
						hubo[4] = hubo[4]*10 + maxv;
						hubo[5] = hubo[5]*10 + minv;
					}
					hubo[5] = hubo[5]*10 + minv;
				}
				if(bigger!=10){
					hubo[0] = buttonlist*10+bigger;
					for(i=0;i<length;i++)
						hubo[0] = hubo[0]*10 + minv;
				}
				if(smaller!=-1){
					hubo[1] = buttonlist*10+smaller;
					for(i=0;i<length;i++)
						hubo[1] = hubo[1]*10 + maxv;
				}
				minv = onlypm;
				for(i=0;i<4;i++){
					if(hubo[i]!=-1)
						minv = min(minv,abs(channel-hubo[i]));
				}
				if(minv == abs(channel-hubo[0]))
					buttonlist = hubo[0];
				else if(minv == abs(channel-hubo[1]))
					buttonlist = hubo[1];
				else if(minv == abs(channel-hubo[2]))
					buttonlist = hubo[2];
				else if(minv == abs(channel-hubo[3]))
					buttonlist = hubo[3];
				hubo[4] = (abs(channel-hubo[4])+log(10, hubo[4])+1);
				hubo[5] = (abs(channel-hubo[5])+log(10, hubo[5])+1);
				onlypm = onlypm < hubo[4] ? onlypm : hubo[4];
				onlypm = onlypm < hubo[5] ? onlypm : hubo[5];
				break;
			}
		}
		buttonlist = log(10, buttonlist)+1 + abs(channel - buttonlist);
		printf("%d", buttonlist < onlypm ? buttonlist :onlypm);
	}
}

//submit
void prob2864(){
	int a, b;
	scanf("%d %d", &a, &b);
	int outputs=0, outputl=0;
	int sums=0, suml=0;
	int lena=log(10, a);
	int lenb=log(10 ,b);
	int i, x, digit;
	for(i=lena;i>=0; i--){
		digit = pow(10, i);
		x = a/digit;
		a = a%digit;
		outputs*=10;
		outputl*=10;
		if(x == 5 || x==6){
			outputs+=5;
			outputl+=6;
		}
		else{
			outputs+=x;
			outputl+=x;
		}
	}
	
	for(i=lenb;i>=0; i--){
		digit = pow(10, i);
		x = b/digit;
		b = b%digit;
		sums*=10;
		suml*=10;
		if(x == 5 || x==6){
			sums+=5;
			suml+=6;
		}
		else{
			sums+=x;
			suml+=x;
		}
	}
	printf("%d %d", outputs+sums, outputl+suml);
}

//submit
void prob1075(){
	int n, f;
	scanf("%d %d", &n, &f);
	int rest = n%f;
	int last = n%100;
	if(last - rest < 0)
		last+=f-rest;
	else
		last-=rest;
	while(last-f>=0){
		last-=f;
	}
	if(last/10 == 0)
		printf("0%d", last);
	else
		printf("%d", last);
	return;
}

//submit
void prob1789(){
	long int n, sum=0;
	int count=1;
	scanf("%ld", &n);
	while(sum<n){
		sum+=count;
		count++;
	}
	if(sum == n) printf("%d", count-1);
	else printf("%d", count-2);
	return;
}

//submit
void prob2407(){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", nCr(a, b));
	return;
}

//submit
void prob1016(){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	int n=2;
	int dif = b-a+1;
	int output = b-a+1;
	while(pow(n, 2) <= dif){
		output -= dif/pow(n,2);
		n++;
	}
		printf("%d", output);
	return;
}

//submit
void prob1964(){
	long long int n;
	scanf("%lld", &n);
	if(n%2==0)
		printf("%lld", ((((n+1)%45678) * (((3*n+2)/2)%45678)))%45678);
	else
		printf("%lld", (((((n+1)/2)%45678) * ((3*n+2)%45678)))%45678);
}

//submit
void prob4504(){
	int n;
	scanf("%d", &n);
	int x;
	while(1){
		scanf("%d", &x);
		if(x==0) break;
		if(x%n==0)
			printf("%d is a multiple of %d\n", x, n);
		else
			printf("%d is NOT a multiple of %d\n", x, n);
	}
	return;
}

//submit
long long int solve(int a, int b, int c){
	if(b==1)
		return a;
	else if(b%2==0){
		long long int x = solve(a, b/2, c)%c;
		return x*x%c;
	}
	else{
		long long int x = solve(a, b/2, c)%c;
		return (((a*x)%c)*x)%c;
	}
	return 0;
}
void prob1629(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%lld", solve(a%c, b, c));
	return;
}

//submit
void prob1834(){
	long long int n;
	scanf("%lld", &n);
	long long int output=0;
	output = n*(n+1)/2*(n-1);
	printf("%lld", output);
	return;
}

//submit
void prob1919(){
	string input1, input2;
	int anal1[26]={0, }, anal2[26]={0, };
	cin>>input1;
	cin>>input2;
	for(int i=0; i< input1.length(); i++)
		anal1[input1.at(i)-'a']++;
	for(int i=0; i< input2.length(); i++)
		anal2[input2.at(i)-'a']++;
	int output=0;
	for(int i=0;i<26;i++)
		output+=abs(anal1[i] - anal2[i]);
	printf("%d", output);
	return;
}	

//yet
void prob1072(){
	long long int x, y;
	long long int winRate, newRate;
	long long int count;
	scanf("%lld %lld", &x, &y);
	winRate = 100*y/x;
	long long int output=1;
	if(winRate >= 99) printf("-1");
	else{
		while(1){
			newRate = 100*(y+output)/(x+output);
			if(newRate!=winRate){
				printf("%lld", output);
				break;
			}
			output++;
		}
	}
	return;
}

//yet
void prob1350(){
	int n;
	int files[100];
	int size;
	long int output=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &files[i]);
	scanf("%d", &size);
	for(int i=0;i<n;i++){
		if(files[i]%size==0)
			output+=files[i]/size;
		else
			output+=files[i]/size+1;
	}
	output*=size;
	printf("%ld", output);
	return;
}

void prob4153(){
	int a, b, c;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		a*=a;
		b*=b;
		c*=c;
		if(a+b+c==0)
			break;
		else if((a+b==c)||(b+c==a)||(c+a==b))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return;
}


int main(){
	prob4153();
	return 0;
} 
