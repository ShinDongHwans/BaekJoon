#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int f=0,b,i;
	cin>>s;
	b=s.length()-1;
	while(f<b){
		if(s[f++]!=s[b--]){
			cout<<"0";
			return 0;
		}
	}
	cout<<"1";
}
