#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include<string.h>

using namespace std;

int input[10][10];
int counting[10][10];
int hubos[3][2];

int count(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(input[i][j] == 1){
				if(i == 0){
					if(j == 0){
						counting[i][j+1]++;
						counting[i+1][j+1]++;
					}
					else if(j == 9){
						counting[i][j-1]++;
						counting[i+1][j-1]++;
					}
					else{
						counting[i][j-1]++;
						counting[i][j+1]++;
						counting[i+1][j-1]++;
						counting[i+1][j+1]++;
					}
					counting[i+1][j]++;
				}
				else if(i == 9){
					if(j==0){
						counting[i][j+1]++;
						counting[i-1][j+1]++;
					}
					else if(j == 9){
						counting[i][j-1]++;
						counting[i-1][j-1]++;
					}
					else{
						counting[i][j-1]++;
						counting[i][j+1]++;
						counting[i-1][j-1]++;
						counting[i-1][j+1]++;
					}
					counting[i-1][j]++;
				}
				else{
					counting[i][j-1]++;
					counting[i][j+1]++;
					counting[i-1][j]++;
					counting[i+1][j]++;
					counting[i-1][j+1]++;
					counting[i+1][j+1]++;
					counting[i-1][j-1]++;
					counting[i+1][j-1]++;
				}
			}
		}
	}
}

int findsolo(){
	int cnt=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(counting[i][j]<4 && input[i][j]==1){
				if(cnt == 3)
					return 1;
				else{
					hubos[cnt][0] = i;
					hubos[cnt++][1] = j;
				}
			}
		}
	}
	if(cnt != 3){
		return 1;
	}
	else 
		return 0;
}

int rAngle(){
	int a = (hubos[0][0]-hubos[1][0])*(hubos[0][0]-hubos[1][0]) + (hubos[0][1] - hubos[1][1])*(hubos[0][1] - hubos[1][1]);	
	int b = (hubos[2][0]-hubos[1][0])*(hubos[2][0]-hubos[1][0]) + (hubos[2][1] - hubos[1][1])*(hubos[2][1] - hubos[1][1]);
	int c = (hubos[0][0]-hubos[2][0])*(hubos[0][0]-hubos[2][0]) + (hubos[0][1] - hubos[2][1])*(hubos[0][1] - hubos[2][1]);
	return ((a+b == c && a==b) || (b+c == a && c==b) || (c+a == b && a==c));
}

int checkFill(){
	for(int i=0; i<10;i++){
		for(int j=0;j<10;j++){
			if(counting[i][j]>3 && input[i][j]==0){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	for(int i=0; i<10; i++){
		string a;
		cin>>a;
		for(int j=0; j<10; j++)
			input[i][j] = a.at(j)-'0';;
	}
	count();
	if(findsolo()||rAngle() == 0||checkFill()){
		printf("0");
		return 0;
	}
	for(int i =0;i<3;i++)
		printf("%d %d\n", hubos[i][0]+1, hubos[i][1]+1);
	return 0;
}