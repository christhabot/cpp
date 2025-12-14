#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll> complete_layers;

int main() 
{
    ll amountq, amount, temp, pos, total;
    
    for (ll i = 0; i <= 1005; i++) 
    {
        ll layer_total = (2*i + 1) * (2*i + 1);
        if (layer_total > 1e9) break;
        complete_layers.insert(layer_total);
    }
    
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        total = 0;
        pos = 0;
        for(int i = 0; i < amount; i++)
        {
            scanf("%lld", &temp);
            pos += temp;
            if(complete_layers.count(pos))
            {
                total++;
            }
        }
        printf("%lld\n", total);
    }
}