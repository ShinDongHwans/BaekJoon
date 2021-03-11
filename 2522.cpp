#include<iostream>
using namespace std;
void space(int i){
	if(i==0)
		return;
	cout<<" ";
	space(i-1);
}
void star(int i){
	if(i==0){
		cout<<"\n";
		return;
	}
	printf("*");
	star(i-1);
}

void draw2(int i,int n){
	if(i==0)
		return;
	star(i);
	space(n-i);
	draw2(--i,n);
}

void draw(int i,int n){
	if(i==n)
		return draw2(i,n);
	star(i);
	space(n-i);
	draw(++i,n);
}

int main(){
	int n;
	scanf("%d",&n);
	draw(1,n);
}
