#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
unordered_map<ll, ll> mp;
 
int main() 
{
    ll amountq, amount, total = 0, temp;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        mp.clear();
        total = 0;
        scanf("%lld", &amount);
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &temp);
            mp[temp]++;
        }
        for(auto p : mp)
        {
            if(p.second >= p.first)
            {
                total += max(0ll, p.second - p.first);
            }
            else
            {
                total += p.second;
            }
        }
        printf("%lld\n", total);
    }
}