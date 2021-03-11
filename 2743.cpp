#include<string>
#include<iostream>
using namespace std;
int main(){
	int i;
	std::string s;
	cin>>s;
	for(i=0;i<s.length();i++){
		if(s[i]<91&&s[i]>64)
			cout<<s[i];
	}
}
