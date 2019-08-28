#include<stdio.h>
/*
double find(int index, double saver){
	if(index == num) return saver;
	else if(saver == 0.0){
		if(input[index]>1.0){
			float fst = find(index+1, input[index]);
			float snd = find(index+1, 0.0);
			return fst>snd ? fst:snd;
		} 
		else return find(index+1, 0.0);
	} 
	else{
		float output = find(index+1, input[index] * saver);	
		return output>saver ? output:saver;
	} 
}
*/
/*
int main(){
	int num;
	double input[10000];
	double dp[10000];
	scanf("%d", &num);
	for(int i=0; i<num; i++)
		scanf("%lf", &input[i]);
	dp[0] = input[0];
	/*
	double output = find(0, 0.0);
	 */
	/*
	for (int i=1; i<num; i++)
        dp[i] = dp[i-1] * input[i];

	double output = dp[0];
    for(int i=1; i<num; i++){
        for (int j=0; j < i; j++){
			double mid = dp[i]/dp[j];
            output = mid > output ? mid : output;
        }
		double mid = dp[i];
        output = mid > output ? mid : output;
    }
	printf("%.3lf\n", output);
}*/

double a[10001];
double dp[10001];
int n;
double f(int x){
    if(x>n)return 0;
    if(x==n)return dp[x]=a[x];
    if(dp[x]!=0)return dp[x];
    return dp[x]=a[x]>a[x]*f(x+1)?a[x]:a[x]*f(x+1);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
    double result=f(1);
    for(int i=2;i<=n;i++){
        if(result<f(i))
            result=f(i);
        //cout<<a[i]<<" "<<f(i)<<endl;
    }
    printf("%.3lf\n",result);
    return 0;
}