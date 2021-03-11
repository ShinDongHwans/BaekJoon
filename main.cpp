#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int abs(int x){return x>0 ? x:-x;}

int max(int a, int b){return a>b ? a:b;}

int min(int a, int b){return a<b ? a:b;}

long int root(long int n){
	long int output = 1;
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

long long int pow(int x, int n){
	long long int output = 1;
	while(n-->0)
		output*=x;
	return output;
}

long long int divup(long int n, long int m){
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

long long int nCr(int n, int r){
	long long int output = 1;
	int bigger = max(r, n-r);
	int multi = n;
	int divis = 1;
	while(multi >bigger){
		output*=multi;
		output/=divis;
		multi--;
		divis++;
	}
	return output;
}

int isPrime(int n){
	if((n!=2 && n%2==0 )|| n==1) return 0;
	for(int i=3;i<=n/3;i+=2){
		if(n%i==0) return 0;
	}
	return 1;
}

//#include<stdio.h>

void prob(){
	char input1, input2;
	while(scanf("%d %d", &input1, &input2)!=EOF){
		printf("%d\n", input1+input2);
	}
}

#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Stack{
	private:
		int len;
		int stack[10000];
	public:
		void push(int x);
		int pop();
		int size();
		int empty();
		int top();
	Stack(){
		len=0;
	}
};

void Stack::push(int x){
	stack[len]=x;
	len++;
	return;
}

int Stack::pop(){
	if(len>0)
		return stack[len--];
	else
		return -1;
}

int Stack::size(){
	return len;
}

int Stack::empty(){
	return !(len==0);
}

int Stack::top(){
	return stack[len];
}

int main(){
	int n;
	std::string input, order, num;
	Stack mystack = Stack();
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> input;
		int len =input.length();
		order = input.substr(0, 3);
		if(order.compare("pop")){
			printf("%d", mystack.pop());
		}
		else if(order.compare("emp")){
			printf("%d", mystack.empty());
		}
		else if(order.compare("top")){
			printf("%d", mystack.top());
		}
		else if(order.compare("siz")){
			printf("%d", mystack.size());
		}
		else{
			cin >> num;
			const char * chars = num.c_str();
			int number = atoi(chars);
			mystack.push(number);
		}
	}
	return 0;
}

