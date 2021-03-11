#include<iostream>
using namespace std;
int main(){
	int n=0,m,p[10]={};
	cin>>m>>m;
	p[0]=m;
	while(n++<9){
		cin>>m;
		p[n]-=m;
		cin>>m;
		p[n]+=p[n-1]+m;
	}
	while(n-->0)
		m=m<p[n]?p[n]:m;
	cout<<m;
}
