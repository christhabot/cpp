#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

int main() 
{
    ll amount;
    scanf("%lld", &amount);
    vec.resize(amount);
    bool good;
    for(ll i = 0; i < amount; i++)
    {
        scanf("%lld", &vec[i]);
        good = false;
        for(ll j = i-1; j >= 0 && !good; j--)
        {
            if(vec[i] < vec[j])
            {
                good = true;
                printf("%lld\n", j+1);
            }
        }
        if(!good)
        {
            printf("-1\n");
        }
    }
}