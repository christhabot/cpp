#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec, targ;

int main() 
{
    ll amountq, amount, sumeven, sumodd, total, minextra, cur;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        targ.resize(amount+1);
        for(int i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
        }
        for(int i = 0; i < amount+1; i++)
        {
            scanf("%lld", &targ[i]);
        }
        total = 0;
        minextra = LLONG_MAX;
        for(int i = 0; i < amount; i++)
        {
            cur = abs(vec[i] - targ[i]);
            ll option1 = (abs(vec[i] - targ[amount]) + abs(targ[amount] - targ[i])) - cur;
            ll option2 = abs(targ[i] - vec[i]) + min(abs(targ[amount] - targ[i]), abs(targ[amount] - vec[i])) - cur;
            minextra = min(minextra, min(option1, option2));
            total += cur;
        }
        printf("%lld\n", total + minextra + 1);
    }
}
