#include<iostream>
using namespace std;
void star(int n){
	if(n==0){
		cout<<"\n";
		return;
	}
	cout<<"* ";
	return star(n-1);
}

void draw(int i, int n){
	if(i%2==0)
		cout<<" ";
	star(n);
	if(i==n) return;
	return draw(i+1, n);
}
int main(){
	int n;
	cin>>n;
	draw(1, n);
}
