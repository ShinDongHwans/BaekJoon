#include<iostream>
using namespace std;

void star(int n){
	int i=2*n-1;
	while(i-->0)
		cout<<"*";
	cout<<"\n";
}
void space(int n){
	if(n--<=0) return;
	cout<<" ";
	return space(n);
}

void redraw(int i, int n){
	space(i--);
	star(n-i-1);
	if(i<0)
		return;
	return redraw(i,n);
}

void draw(int i, int n){
	space(i++);
	star(n-i+1);
	if(i==n)
		return redraw(i-2,n);
	return draw(i,n);
}

int main(){
	int n;
	cin>>n;
	if(n==1)cout<<"*";
	else draw(0, n);
}
