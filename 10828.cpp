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
		return stack[--len];
	else
		return -1;
}

int Stack::size(){
	return len;
}

int Stack::empty(){
	return (len==0);
}

int Stack::top(){
	if(len == 0)
		return -1;
	return stack[len-1];
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
		if(!order.compare("pop")){
			printf("%d\n", mystack.pop());
		}
		else if(!order.compare("emp")){
			printf("%d\n", mystack.empty());
		}
		else if(!order.compare("top")){
			printf("%d\n", mystack.top());
		}
		else if(!order.compare("siz")){
			printf("%d\n", mystack.size());
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
