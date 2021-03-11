#include <iostream>
std::string s;
char t[100],k,i,l;
int main(){
	while(1){
		getline(std::cin,s);
		k=0;
		l=s.length();
		if(l==1&&s[0]=='.')
			break;
		for(i=0;i<l&&k>=0;i++){
			if(s[i]==40||s[i]==91)
				t[k++]=s[i];
			else if(s[i]==41){
				if(k==0||t[k---1]!=40)
					k=-1;
			}
			else if(s[i]==93){
				if(k==0||t[k---1]!=91)
					k=-1;
			}
		}
		if(k!=0)
			std::cout<<"no\n";
		else
			std::cout<<"yes\n";	
	}
}
