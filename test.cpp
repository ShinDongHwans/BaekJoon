#include <iostream>
double a,b,c,d,e,f,k;
int main(){
	std::cin>>a>>b>>c>>d>>e>>f;
	k=e-a;
	c-=a;
	d-=b;
	if(c)
		k=d/c*k+b-f;
	std::cout<<((a>0)-(a<0))*((b>=0)-(b<0))*z((k>0)-(k<0));
}
