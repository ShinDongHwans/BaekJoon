#include<iostream> 
using namespace std;int main(){int o=0,i,n,x,t[1001]={};cin>>n;for(i=0;i<n;i++){cin>>x;t[x]++;}for(i=1;i<1001;i++){while(t[i]-->0)o+=i*n--;}cout<<o;}
