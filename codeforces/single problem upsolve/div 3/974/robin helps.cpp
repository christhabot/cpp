#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() 
{
    ll amountq, amount, threshold, cur, curg, res;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld", &amount, &threshold);
        curg = 0;
        res = 0;
        while(amount--)
        {
            scanf("%d", &cur);
            if(cur >= threshold)
            {
                curg += cur;
            }
            else if(cur == 0 && curg > 0)
            {
                curg--;
                res++;
            }
        }
        printf("%lld\n", res);
    }
}