#include<stdio.h>

void hotel(){
	int h, w, n;
	int front, back;
	scanf("%d %d %d", &h, &w, &n);
	if(h==1){
		printf("%d\n", h*100+n);
	} 
	else if(n%h==0){
		
		front=h;
		back=n/h;
		printf("%d\n", 100*front+back);
	}
	else{
		front=n%h;
		back=1+n/h;
		printf("%d\n", 100*front+back);
	}
	return;
	
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		hotel();
	}
}
