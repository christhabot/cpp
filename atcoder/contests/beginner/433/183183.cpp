#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec, cnt;
map<ll, vector<ll>> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll amount, target;
    scanf("%lld %lld", &amount, &target);
    vec.resize(amount);

    for(ll i = 0; i < amount; i++)
    {
        scanf("%lld", &vec[i]);
        ll d = to_string(vec[i]).length();
        mp[d].push_back(i);
    }

    ll ans = 0;

    for(auto &p : mp)
    {
        ll d = p.first;
        vector<ll> &idx = p.second;

        ll pw = 1;
        for(ll i = 0; i < d; i++)
        {
            pw = (pw * 10) % target;
        }

        map<ll, ll> freq;
        for(ll i = 0; i < amount; i++)
        {
            ll v = (vec[i] * pw) % target;
            freq[v]++;
        }

        for(ll j : idx)
        {
            ll need = (target - (vec[j] % target)) % target;
            ans += freq[need];
        }
    }

    printf("%lld\n", ans);

    return 0;
}
