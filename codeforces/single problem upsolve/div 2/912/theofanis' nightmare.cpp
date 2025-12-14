#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec, suf;

int main() 
{
    ll amountq, amount, cur, idx, total;
    scanf("%lld", &amountq);
    while(amountq--) 
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        for(int i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
        }
        suf.resize(amount);
        suf[amount-1] = vec[amount-1];
        for(int i = amount-2; i >= 0; i--)
        {
            suf[i] = suf[i+1] + vec[i];
        }
        idx = 1;
        cur = 0;
        total = 0;
        for(int i = 0; i < amount; i++)
        {
            cur += vec[i];
            if(suf[i+1] > 0)
            {
                total += cur * idx;
                idx++;
                cur = 0;
            }
        }
        total += cur*idx;
        printf("%lld\n", total);
    }
    return 0;
}
