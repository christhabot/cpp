#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> weights;
vector<bool> active;

int main() 
{
    ll cur, idx;
    ll amountp, amountq;
    scanf("%lld %lld", &cur, &amountp);
    weights.resize(amountp);
    active.assign(amountp, false);
    for(ll i = 0; i < amountp; i++)
    {
        scanf("%lld", &weights[i]);
    }
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &idx);
        idx--;
        if(active[idx])
        {
            cur -= weights[idx];
        }
        else
        {
            cur += weights[idx];
        }
        active[idx] = !active[idx];
        printf("%lld\n", cur);
    }
}