#include<stdio.h>

int num=0;
int money;
int price[101];
int sorted[101];
int saver[10001]={1,};

int sorting(int count, int num) {
	if (count == num) return count;
	else {
		int min = 10001;
		int index = -1;
		for (int i = 1; i < num; i++) {
			if (min >= price[i]) {
				index = i;
				min = price[i];
			}
			else if(min == price[i])
				price[i]=10002;
		}
		if(min == 10001) return count;
		sorted[count] = min;
		price[index] = 10001;
	}
	return sorting(count+1, num);
}

int search(int index, int coinNum){
	if(index==coinNum) return saver[money];
	else{
		int i;
		for(i = 1; i <= money; i++)
        {
            if(i- sorted[index] >= 0) saver[i] += saver[i-sorted[index]];
		}
        return search(index+1, coinNum);
	}
}

int main(){
	scanf("%d %d", &num, &money);
	int i=1;
	for(;i<=num;i++){
		scanf("%d", &price[i]);
	}
	saver[0]=1;
	printf("%d",search(1, sorting(1, num+1)));
	return 0;
} 
