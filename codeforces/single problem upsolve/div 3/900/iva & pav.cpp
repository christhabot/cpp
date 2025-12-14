#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll ALL_ONES = (1LL << 60) - 1;

vector<ll> seg;

ll amount;

void build()
{
    for(ll i = amount-1; i > 0; i--)
    {
        seg[i] = seg[i << 1] & seg[i << 1 | 1];
    }
}

void modify(ll pos, ll val)
{
    pos += amount;
    for(seg[pos] = val; pos > 1; pos >>= 1)
    {
        seg[pos >> 1] = seg[pos] & seg[pos ^ 1];
    }
}

ll query(ll l, ll r) {
    ll res = ALL_ONES;
    l += amount;
    r += amount + 1;
    while(l < r) {
        if(l & 1) res &= seg[l++];
        if(r & 1) res &= seg[--r];
        l >>= 1;
        r >>= 1;
    }
    return res;
}

vector<ll> vec;

int main() 
{
    ll amountq, amountq2, pl, l, r, k, mid;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        seg.assign(2*amount, 0);
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
            seg[amount+i] = vec[i];
        }
        build();
        scanf("%lld", &amountq2);
        for(ll i = 0; i < amountq2; i++)
        {
            scanf("%lld %lld", &pl, &k);
            pl--;
            l = pl;
            r = amount-1;
            while(l < r)
            {
                mid = (l + r + 1) / 2;
                if(query(pl, mid) >= k)
                {
                    l = mid;
                }
                else
                {
                    r = mid-1;
                }
            }
            printf("%lld ", query(pl, l) >= k ? l+1 : -1ll);

        }
        printf("\n");
    }
}