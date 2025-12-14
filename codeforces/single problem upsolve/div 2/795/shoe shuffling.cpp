#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

int main() 
{
    ll amountq, amount, first, last, bef;
    bool good;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
        }
        bef = 0;
        good = true;
        for(ll i = 1; i < amount && good; i++)
        {
            if(vec[i] != vec[bef])
            {
                if(i - bef < 2)
                {
                    good = false;
                }
                else
                {
                    bef = i;
                }
            }
        }
        if(amount-1 - bef < 1)
        {
            good = false;
        }
        if(good)
        {
            bef = 0;
            for(ll i = 1; i < amount; i++)
            {
                if(vec[i] != vec[bef])
                {
                    printf("%lld ", bef+1);
                    bef = i;
                }
                else
                {
                    printf("%lld ", i+1);
                }
            }
            printf("%lld\n", bef+1);
        }
        else
        {
            printf("-1\n");
        }
    }
}