#include<stdio.h>
#include<string>
#include<stdlib.h>


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
	int n,num;
	char input[10];
	Queue q = Queue();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",input);
		switch(input[0]){
			case 's':
				printf("%d\n",q.size());
				break;
			case 'e':
				printf("%d\n",q.empty());
				break;
			case 'f':
				printf("%d\n",q.front());
				break;
			case 'b':
				printf("%d\n",q.back());
				break;
			case'p':
				if(input[1]=='o')
					printf("%d\n",q.pop());
                else{
			        scanf("%d",&n);
			        q.push(num);
				}
		}
	}
	return 0;
}
