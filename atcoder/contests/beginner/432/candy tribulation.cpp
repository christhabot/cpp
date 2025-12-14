#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

int main() 
{
    ll amount, weights, weightb, thing, l = LLONG_MIN, r = LLONG_MAX, w, res = 0;
    bool found;
    scanf("%lld %lld %lld", &amount, &weights, &weightb);
    vec.resize(amount);
    ll step = weightb - weights;
    for(ll i = 0; i < amount; i++)
    {
        scanf("%lld", &vec[i]);
        if(i == 0)
        {
            thing = (vec[i] * weights) % step;
        }
        else if((vec[i] * weights) % step != thing)
        {
            printf("-1\n");
            return 0;
        }
        l = max(l, vec[i] * weights);
        r = min(r, vec[i] * weightb);
    }
    if(l > r)
    {
        printf("-1\n");
        return 0;
    }
    w = r;
    found = false;
    while(!found)
    {
        if(w < l)
        {
            printf("-1\n");
            return 0;
        }
        if(w % step == thing)
        {
            found = true;
        }
        w--;
    }
    w++;
    for(ll i = 0; i < amount; i++)
    {
        res += (w - vec[i] * weights) / step;
    }
    printf("%lld", res);
}