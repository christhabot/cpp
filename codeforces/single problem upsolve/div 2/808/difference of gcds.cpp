#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> res;

int main() 
{
    ll amountq, amount, l, r;
    bool good;
    scanf("%lld", &amountq);
    while(amountq--) 
    {
        scanf("%lld %lld %lld", &amount, &l, &r);
        good = true;
        res.resize(amount);
        for(int i = 1; i <= amount && good; i++)
        {
            res[i-1] = ((l-1)/i+1) * i;
            if(res[i-1] > r)
            {
                good = false;
            }
        }
        printf("%s\n", good ? "YES" : "NO");
        if(good)
        {
            for(int i = 0; i < amount; i++)
            {
                printf("%lld ", res[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
