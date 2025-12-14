#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll,ll>> vec;

int main() 
{
    ll amount, amountq, cur, total = 0;
    bool found;
    scanf("%lld", &amount);
    vec.resize(amount);
    for(int i = 0; i < amount; i++)
    {
        scanf("%lld %lld", &vec[i].first, &vec[i].second);
    }
    scanf("%lld", &amountq);
    for(int q = 0; q < amountq; q++)
    {
        scanf("%lld", &cur);
        found = false;
        for(int i = 0; i < amount && !found; i++)
        {
            if(cur >= vec[i].first && cur <= vec[i].second)
            {
                found = true;
            }
        }
        if(found)
        {
            total++;
        }
    }
    cout << total;
}