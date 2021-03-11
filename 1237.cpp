#include<iostream>
using namespace std;

const int MAX = 8+1;
int num[MAX],arr[MAX] ,n, m;
bool visited[MAX];

void get(int k){
	int i,s;
	cin>>num[k];
	for(i=1;i<k;i++){
		if(num[k]<num[i])
			break;
	}
	for(;i<k;i++){
		s=num[k];
		num[k]=num[i];
		num[i]=s;
	}
	return;
}

void draw(int k){
	int i,j;
	if(k == m){
		for(i=0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(i=1;i<=n;i++){
		if(!visited[i]&&arr[k-1]<=num[i]&&(num[i]!=num[i-1]||visited[i-1]==true)){
			if(num[i]==num[i+1])
				visited[i]=true;
			arr[k]=num[i];
			draw(k+1);
			visited[i]=false;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		get(i);
	draw(0);
}
