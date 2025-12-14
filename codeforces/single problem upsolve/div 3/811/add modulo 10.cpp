#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

ll next_op(ll x) 
{
    return x + x % 10;
}

int main() 
{
    ll amountq, amount;
    bool zf, nzf, good, mgood;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        zf = false;
        nzf = false;
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
            if(vec[i] % 5 == 0)
                zf = true;
            else
                nzf = true;
        }

        good = false;
        if(zf && nzf)
        {
            good = false;
        }
        else if(zf)
        {
            for(ll i = 0; i < amount; i++)
                vec[i] += vec[i] % 10;
            mgood = true;
            for(ll i = 1; i < amount; i++)
                if(vec[i] != vec[0])
                    mgood = false;
            good = mgood;
        }
        else
        {
            bool type2 = false, type12 = false;
            for(ll i = 0; i < amount; i++)
            {
                ll x = vec[i];
                while(x % 10 != 2)
                    x = next_op(x);
                if(x % 20 == 2)
                    type2 = true;
                else
                    type12 = true;
            }
            good = !(type2 && type12);
        }

        printf("%s\n", good ? "YES" : "NO");
    }
}
