#include<iostream>
using namespace std;

void space(int x){
	if(x--<=0) return;
	cout << " ";
	return space(x);
}

void star(int n, int i){
	space(n-i-1);
	cout << "*";
	space(i*2-1);
	cout << "*\n";
	return;
}

void draw(int n){
	int i;
	space(n-1);
	cout << "*\n";
	for(i=1;i<n-1;i++)
		star(n, i);
	if(n!=1){	
		for(i=1;i<2*n;i++)
			cout << "*";
	}
}

int main(){
	int n;
	cin >> n;
	draw(n);
}
