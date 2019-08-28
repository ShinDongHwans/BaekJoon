#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include<string.h>

using namespace std;

int main(){
	string input;
	cin>>input;
	int state = 0;
	for(int i=0; i< input.length(); i++){
		if(input.at(i) == '1'){
			if(state == 0)
				state = 1;
			else if(state == 3)
				state = 4;
			else if(state == 4)
				state = 7;
			else if(state == 6)
				state = 0;
			else if(state == 7)
				state = 7;
			else if(state == 8)
				state = 0;
			else 
				state = -1;
		}
		else{
			if(state == 0) state = 6;
			else if(state == 1) state = 2;
			else if(state == 2) state = 3;
			else if(state == 3) state = 3;
			else if(state == 4) state = 6;
			else if(state == 7) state = 8;
			else if(state == 8) state = 3;
			else state = -1;
		}
	}
	if(state == 0 || state == 4 || state == 7) printf("SUBMARINE\n");
	else printf("NOISE\n");
	return 0;	
}