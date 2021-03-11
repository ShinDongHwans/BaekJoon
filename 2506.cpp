#include<iostream>
using namespace std;int main(){int n,i=0,s=0,l[100000];cin>>n;while(n--){cin>>l[i];i=l[i]==0?i-1:i+1;if(i<0)i=0;}while(++n<i)s+=l[n];cout<<s;}
