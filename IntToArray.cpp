int arraySum(int n[], int m[]){
	int length = sizeof(n)/sizeof(*n);
	int output[length]={0,};
	int saver=0;
	while(int i=length-1;i>=0;i--){
		saver += n[i]+m[i];
		output[i] = saver%10;
		saver/=10;
	}
	return output;
}

int intToArray(int n){
	int output[100];
	int index=99;
	while(n>0){
		output[index]=n%10;
		n/=10;
	}
	return output;
}

//yet
int answer[100];
void prob(){
	int a, b;
	scanf("%d %d", &a, &b);
	for
}	
