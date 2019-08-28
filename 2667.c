#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include<string.h>

using namespace std;
int size;
int map[25][25];
int answer = 0;
int store[313];
int answers[313];

int village(int i, int j) {
	if (i < 0 || i >= size || j < 0 || j >= size) return 0;
	else if (map[i][j] == 1) {
		map[i][j] = 0;
		return 1 + village(i - 1, j) + village(i + 1, j) + village(i, j - 1) + village(i, j + 1);
	}
	else return 0;
}

int search() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] == 1)
				store[answer++] = village(i, j);
		}
	}
}

void sorting(int count) {
	if (count == answer) return;
	else {
		int min = 626;
		int index = -1;
		for (int i = 0; i < answer; i++) {
			if (min > store[i]) {
				index = i;
				min = store[i];
			}
		}
		answers[count] = min;
		store[index] = 626;
	}
	return sorting(count+1);
}

int main() {
	scanf("%d", &size);	
	for (int i = 0; i < size; i++) {
		string a;
		cin>>a;
		for (int j = 0; j < size; j++) {
			map[i][j] = a.at(j)-'0';
			
		}
	}
	search();
	sorting(0);
	if(answer == 0)
		printf("0");
	else{
		printf("%d\n", answer);
		for (int i = 0; i < answer-1; i++)
			printf("%d\n", answers[i]);
		printf("%d", answers[answer - 1]);
	}
	return 0;	
}