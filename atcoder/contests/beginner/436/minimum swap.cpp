#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;
vector<bool> explored;

int main() 
{
    ll amount, siz, cur;
    ll total = 0;
    scanf("%lld", &amount);
    vec.resize(amount);
    explored.assign(amount, false);
    for(ll i = 0; i < amount; i++)
    {
        scanf("%lld", &vec[i]);
        vec[i]--;
    }
    for(ll i = 0; i < amount; i++)
    {
        if(!explored[i] && vec[i] != i)
        {
            cur = i;
            siz = 0;
            while(!explored[cur])
            {
                explored[cur] = true;
                cur = vec[cur];
                siz++;
            }
            if(siz >= 2) total += (siz*(siz-1))/2;
        }
    }
    printf("%lld\n", total);
}
