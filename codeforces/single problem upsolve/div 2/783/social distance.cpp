#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

int main() 
{
    ll amountq, amount, chairs, right, pos;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld", &amount, &chairs);
        vec.resize(amount);
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
        }
        sort(vec.begin(), vec.end(), greater<ll>());
        pos = 0;
        for(ll i = 0; i < amount; i++)
        {
            pos += vec[i] + 1;
        }
        pos += vec[0] - vec[amount-1];
        printf("%s\n", pos <= chairs ? "YES" : "NO");
    }
}