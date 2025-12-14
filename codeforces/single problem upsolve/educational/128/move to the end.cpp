#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;
vector<ll> pref; // max
vector<ll> suff; // sum

int main() 
{
    ll amountq, amount, temp, res;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        pref.resize(amount);
        suff.resize(amount);
        scanf("%lld", &vec[0]);
        pref[0] = vec[0];
        for(ll i = 1; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
            pref[i] = max(pref[i-1], vec[i]);
        }
        suff[amount-1] = vec[amount-1];
        for(ll i = amount-2; i >= 0; i--)
        {
            suff[i] = suff[i+1] + vec[i];
        }
        for(ll k = 1; k < amount; k++)
        {
            res = suff[amount-k];
            res += max(0ll, pref[amount-k-1] - vec[amount-k]);
            printf("%lld ", res);
        }
        printf("%lld\n", suff[0]);
    }
}