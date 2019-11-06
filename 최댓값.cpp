#include <stdio.h>
int num[10005];
int n, m;
int k;
int find(int x, int y, int z){
	if((y==z&&num[y]!=x)||(y>z))
		return -1;
	if(num[(y+z)/2]==x)
		return (y+z)/2;
	else if(num[(y+z)/2]<x)
		return find(x, (y+z)/2+1,z);
	else{
		if(y+z==3)
			return find(x, 2, 2);
		return find(x, y, (y+z)/2-1);		
	}
	
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", &num[i]);
	}
	
    scanf("%d", &m);
    for(int i=0; i<m;i++){
    	scanf("%d", &k);
    	int a=find(k, 1, n);
    	if(a!=-1)
	    	printf("%d\n",a);
	    else
	    	printf("-1\n");
	}
}
