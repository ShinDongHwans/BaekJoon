#include <stdio.h>

int used[1000001];
long long count;

int main(void)
{
    long long min, max;
    scanf("%lld%lld", &min, &max);

    for(long long i = 2; i*i <= max; i++){
        long long n = (min-1) / (i*i) + 1;
        while(n*i*i <= max){
            if(!used[n*i*i-min]){
                used[n*i*i-min]++;
                count++;
            }
            n++;
        }
    }
    printf("%lld", max-min+1-count);
    return 0;
}
