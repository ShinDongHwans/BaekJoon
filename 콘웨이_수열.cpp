#include <stdio.h>
int array[10002]={0, 1, 1};
int n;
void conway(int i){
	if(i>n)
		return;
	int k=array[i-1];
	array[i]=array[k]+array[i-k];
	return conway(i+1);
}

int main(){
	scanf("%d", &n);
	conway(3);
	printf("%d", array[n]);
}
