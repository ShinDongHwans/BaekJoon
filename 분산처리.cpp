#include<stdio.h>
#include<math.h>

int start_game(int n, int k){
	if(k==1)
		return n%10;
		
	if(n%10==1||n%10==5||n%10==6)
		return n%10;
	if(n%10==0)
		return 10;
		
	if(k==0){
		int x;
		if(n!=4 && n!=9)
			x=(int)pow(n, 4)%10;
		else
			x=(int)pow(n, 2)%10;
		return x;
	}
	
	if(k>5){
		switch(n%10){
			case 2:
				return start_game(n, k%4);
			case 3:
				return start_game(n, k%4);
			case 4:
				return start_game(n, k%2);
			case 7:
				return start_game(n, k%4);
			case 8:
				return start_game(n, k%4);
			case 9:
				return start_game(n, k%2);
		}
	}
	
	return start_game(n, k-1)*n%10;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++){	
		int num, k;		
		scanf("%d %d", &num, &k);
		printf("%d\n", start_game(num, k));
	}
}
