#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Queue{
	private:
		int len;
		int frt;
		int bck;
		int stack[10000];
	public:
		void push(int x);
		int pop();
		int size();
		int empty();
		int front();
		int back();
	Queue(){
		len=0;
		frt=0;
		bck=0;
	}
};

void Queue::push(int x){
	if(bck == 10000)
		bck = 0;
	len++;
	stack[bck++]=x;
	return;
}

int Queue::pop(){
	if(len>0){
		if(frt == 10000)
			frt = 0;
		len --;		
		return stack[frt++];
	}
	else
		return -1;
}

int Queue::size(){
	return len;
}

int Queue::empty(){
	return (len==0);
}

int Queue::front(){
	if(len == 0)
		return -1;
	return stack[frt];
}


int Queue::back(){
	if(len == 0)
		return -1;
	else if(bck != 0)
		return stack[bck-1];
	else
		return stack[9999];
}

int main(){
	int n;
	std::string input, order, num;
	Queue myqueue = Queue();
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> input;
		int len =input.length();
		order = input.substr(0, 3);
		if(!order.compare("pop")){
			printf("%d\n", myqueue.pop());
		}
		else if(!order.compare("emp")){
			printf("%d\n", myqueue.empty());
		}
		else if(!order.compare("fro")){
			printf("%d\n", myqueue.front());
		}
		else if(!order.compare("bac")){
			printf("%d\n", myqueue.back());
		}
		else if(!order.compare("siz")){
			printf("%d\n", myqueue.size());
		}
		else{
			cin >> num;
			const char * chars = num.c_str();
			int number = atoi(chars);
			myqueue.push(number);
		}
	}
	return 0;
}
