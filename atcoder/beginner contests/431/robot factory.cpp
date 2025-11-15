#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> heads, bodies;

int main() 
{
    ll amounth, amountb, target, found = 0;
    scanf("%lld %lld %lld", &amounth, &amountb, &target);
    heads.resize(amounth);
    bodies.resize(amountb);
    for(ll i = 0; i < amounth; i++)
    {
        scanf("%lld", &heads[i]);
    }
    for(ll i = 0; i < amountb; i++)
    {
        scanf("%lld", &bodies[i]);
    }
    sort(heads.begin(), heads.end());
    sort(bodies.begin(), bodies.end());
    ll i = 0, j = 0;
    while(i < amounth && j < amountb)
    {
        if(heads[i] <= bodies[j])
        {
            found++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if(found >= target)
        printf("Yes");
    else
        printf("No");
}