#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int a[26]={},i;
	cin>>s;
	for(i=0;i<s.length();i++)
		a[s[i]-97]++;
	for(i=0;i<26;i++)
		cout << a[i] <<" ";
}
