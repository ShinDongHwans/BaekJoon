#include<stdio.h>
int abs(int x){return x>0 ? x:-x;}

int max(int a, int b){return a>b ? a:b;}

int min(int a, int b){return a<b ? a:b;}

int root(int n){
	int output = 1;
	while(output*output <= n)
		output++;
	return output-1;
}

int log(int n, int x){
	if(x==0) return 0;
	int compare = 1;
	int output = 0;
	while(compare <= x){
		compare*=n;
		output++;
	}
	return output-1;
}

int pow(int x, int n){
	int output = 1;
	while(n-->0)
		output*=x;
	return output;
}

long long int div_up(long int n, long int m){
	if(n%m!=0) return n/m+1;
	else return n/m;
}

void prob1107(){
	//Initializing Step
	int channel, num, button[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	scanf("%d %d", &channel, &num);
	for(int i=0;i<num;i++){
		int x;
		scanf("%d", &x);
		button[x] = -1;
	}
	//If all buttons are wrong, we just move + -
	int onlypm = abs(channel - 100);
	if(num == 10){
		printf("%d", onlypm);
		return;
	}
	else{
		int x = channel;
		int buttonlist = 0;
		int length = log(10, x) + 1;
		while(length-->0){
			int digit = x/pow(10, length);
			if(button[digit]==digit){
				buttonlist = buttonlist*10+digit;
				x=x%pow(10, length);
			}
			else{
				int maxv=-1, minv=10, nzerominv=10;
				int bigger=10, smaller = -1;
				int hubo[6]={-1,-1,-1,-1,-1,-1};
				int i=-1, c;
				while(i++<10){
					c = button[i];
					if(c==i){
						maxv = max(maxv, i);
						minv = min(minv, i);
						if(nzerominv == 10 && i!=0)
							nzerominv = min(nzerominv, i);
					}
				}
				i=0;
				while(i<digit){
					if(button[i]==i)
						smaller = max(smaller, i);
					i++;
				}
				i=digit+1;
				while(i<10){
					if(button[i]==i)
						bigger = min(bigger, i);
					i++;
				}
				if(length != log(10, channel) && buttonlist > 0){
					hubo[2] = buttonlist;
					hubo[3] = buttonlist;
					int copy, l, count, sub;
					while(hubo[2]-- && hubo[2] >=0){
						copy = hubo[2];
						count=0;
						l = log(10, copy)+1;
						while(l-->0){
							sub = pow(10, l);
							if(button[copy/sub] == copy/sub) count++;
							copy = copy%sub;
						}
						if(count == log(10, hubo[2])+1)
							break;
					}
					while(hubo[3]++ && hubo[3] <= channel+onlypm){
						copy = hubo[3];
						count=0;
						l = log(10, copy)+1;
						while(l-->0){
							sub = pow(10, l);
							if(button[copy/sub] == copy/sub) count++;
							copy = copy%sub;
						}
						if(count == log(10, hubo[3])+1)
							break;
					}					
					for(i=0;i<length+1;i++){
						hubo[2] = hubo[2]*10 + maxv;
						hubo[3] = hubo[3]*10 + minv;
					}
				}
				
				hubo[4] = 0;
				hubo[5] = nzerominv;
				if(channel < 10){
					hubo[4] = hubo[4]*10 + maxv;
					hubo[5] = hubo[5]*10 + minv;
				}
				else{
					for(i=0;i<log(10, channel);i++){
						hubo[4] = hubo[4]*10 + maxv;
						hubo[5] = hubo[5]*10 + minv;
					}
					hubo[5] = hubo[5]*10 + minv;
				}
				if(bigger!=10){
					hubo[0] = buttonlist*10+bigger;
					for(i=0;i<length;i++)
						hubo[0] = hubo[0]*10 + minv;
				}
				if(smaller!=-1){
					hubo[1] = buttonlist*10+smaller;
					for(i=0;i<length;i++)
						hubo[1] = hubo[1]*10 + maxv;
				}
				minv = onlypm;
				for(i=0;i<4;i++){
					if(hubo[i]!=-1)
						minv = min(minv,abs(channel-hubo[i]));
				}
				if(minv == abs(channel-hubo[0]))
					buttonlist = hubo[0];
				else if(minv == abs(channel-hubo[1]))
					buttonlist = hubo[1];
				else if(minv == abs(channel-hubo[2]))
					buttonlist = hubo[2];
				else if(minv == abs(channel-hubo[3]))
					buttonlist = hubo[3];
				hubo[4] = (abs(channel-hubo[4])+log(10, hubo[4])+1);
				hubo[5] = (abs(channel-hubo[5])+log(10, hubo[5])+1);
				onlypm = onlypm < hubo[4] ? onlypm : hubo[4];
				onlypm = onlypm < hubo[5] ? onlypm : hubo[5];
				break;
			}
		}
		buttonlist = log(10, buttonlist)+1 + abs(channel - buttonlist);
		printf("%d", buttonlist < onlypm ? buttonlist :onlypm);
	}
}

int main(){
	prob1107();
	return 0;
} 
