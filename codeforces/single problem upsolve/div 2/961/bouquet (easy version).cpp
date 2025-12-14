#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> mp;

int main() 
{
    ll amountq, amount, cur, a, b, money, best;
    scanf("%lld", &amountq);
    while (amountq--) 
    {
        scanf("%lld %lld", &amount, &money);
        mp.clear();
        for(int i = 0; i < amount; i++)
        {
            scanf("%lld", &cur);
            mp[cur]++;
        }

        best = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ll x = it->first, cx = it->second;
            ll next_cx = 0;
            auto next_it = next(it);
            if(next_it != mp.end() && next_it->first == x+1) 
                next_cx = next_it->second;

            ll max_bouquet = 0;
            for(ll k1 = 0; k1 <= min(cx, money / x); k1++)
            {
                ll remaining = money - k1 * x;
                ll k2 = min(next_cx, remaining / (x+1));
                max_bouquet = max(max_bouquet, k1 * x + k2 * (x+1));
            }
            best = max(best, max_bouquet);
        }
        printf("%lld\n", best);
    }
    return 0;
}
