#include<string>
#include<iostream>

using namespace std;

int main(){
	std::string input;
	int n, i, j, l, cnt, check;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		check = 0;
		cin >> input;
		l = input.length();
		cnt=0;
		for(j=0;j<l;j++){
			if(input[j] == '(') cnt++;
			else if(input[j]==')') cnt--;
			if(cnt < 0){
				cout << "NO\n";
				check = 1;
				break;
			}
		}
		if(check == 0){			
			if(cnt==0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
