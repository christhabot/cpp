#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;
vector<ll> pref;

ll getpref(ll n, ll y)
{
    return pref[n-y-1];
}

int main() 
{
    ll amountq, amount, target, x, res = LLONG_MAX;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        res = LLONG_MAX;
        scanf("%lld %lld", &amount, &target);
        vec.resize(amount);
        pref.resize(amount);
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
        }
        sort(vec.begin(), vec.end());
        pref[0] = vec[0];
        for(int i = 1; i < amount; i++)
        {
            pref[i] = pref[i-1] + vec[i];
        }
        res = LLONG_MAX;
        for(ll y = 0; y < amount; y++) 
        {
            ll sumFirst = pref[amount - y - 1];
            ll num = target - sumFirst + vec[0];
            ll x = num / (y + 1);
            if(x * (y + 1) > num) x--;
            x = vec[0] - x;
            res = min(res, y + max(0LL, x));
        }

        printf("%lld\n", res);
    }
}