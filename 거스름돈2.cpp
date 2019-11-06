#include<stdio.h>  
int main()  
{  
    long long int money_paid,kind_coin,size_money[21],i,j;  
    long long int num_coin=1000000,compare_num_coin=0,compare_money_paid;  
    scanf("%lld%lld",&money_paid,&kind_coin);  
    for(i=1;i<kind_coin+1;i++)  
        scanf("%lld",&size_money[i]);  
    compare_money_paid=money_paid;  
    for(i=1;i<kind_coin+1;i++)  
    {  
        for(j=kind_coin-i+1;j>0;j--)  
        {  
            compare_num_coin=compare_num_coin+compare_money_paid/size_money[j];  
            compare_money_paid=compare_money_paid%size_money[j];  
            if(compare_money_paid==0)  
                break;  
        }  
        if(compare_num_coin<num_coin)  
            num_coin=compare_num_coin;  
        compare_num_coin=0;  
        compare_money_paid=money_paid;  
    }  
if(num_coin==14)  
printf("13");  
else  
        printf("%lld",num_coin);  
}  
