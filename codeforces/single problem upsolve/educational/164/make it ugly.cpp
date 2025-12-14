#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() 
{
    ll amountq;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        ll amount;
        scanf("%lld", &amount);
        
        ll zero;
        scanf("%lld", &zero);
        
        ll lst = -1;
        ll ans = amount;
        
        for(ll i = 1; i < amount; i++)
        {
            ll temp;
            scanf("%lld", &temp);
            if(temp != zero)
            {
                ans = min(ans, i - lst - 1);
                lst = i;
            }
        }
        
        ans = min(ans, amount - lst - 1);
        
        if(ans == amount)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", ans);
        }
    }
}