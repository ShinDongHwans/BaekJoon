#include<iostream>
using namespace std;
int main(){
	int o,m,n,s;
	cin>>m>>o;
	cin>>m>>n;
	s=n-m;
	cin>>m>>n;
	if(n>m)s+=n-m;
	if(s>0)o+=s;
	cout<<o;
}
