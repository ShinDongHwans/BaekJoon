#include <stdio.h>
#include <string.h>
int hour, minute;
int class_time;
int break_time;
int number_of_class;
int lunch_timing;
int lunch_time;

void runtime(int x){
	minute+=x;
	if(minute/60){
		hour+=minute/60;
		minute%=60;
	}
}

int main(){
	int i; 
	scanf("%d %d %d %d %d %d %d", &hour, &minute, &class_time, &break_time, &number_of_class, &lunch_timing, &lunch_time);
	
	for(i=1;i<=lunch_timing;i++){
		printf("%d:%02d-", hour, minute);
		runtime(class_time);
		printf("%d:%02d %d교시\n", hour, minute, i);
		if(i!=lunch_timing)
			runtime(break_time);
	}
	
	printf("%d:%02d-", hour, minute);
	runtime(lunch_time);
	printf("%d:%02d 점심시간\n", hour, minute);
	
	for(i;i<=number_of_class;i++){
		printf("%d:%02d-", hour, minute);
		runtime(class_time);
		printf("%d:%02d %d교시\n", hour, minute, i);
		runtime(break_time);
	}
}
