#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b;
int main() 
{
    ll amountq, amounta, amountb, rounds, suma;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld %lld", &amounta, &amountb, &rounds);
        a.resize(amounta);
        b.resize(amountb);
        for(ll i = 0; i < amounta; i++)
        {
            scanf("%lld", &a[i]);
        }
        for(ll i = 0; i < amountb; i++)
        {
            scanf("%lld", &b[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        if(b.back() > a[0])
        {
            swap(a[0], b.back());
        }
        
        rounds--;
        
        if(rounds & 1)
        {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            swap(a.back(), b[0]);
        }
        
        suma = 0;
        for(ll num : a) suma += num;
        
        printf("%lld\n", suma);
    }
}