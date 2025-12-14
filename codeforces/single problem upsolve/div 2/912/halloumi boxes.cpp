#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec, suf;

int main() 
{
    ll amountq, amount, k, cur, fir, prev;
    bool allsame, sorted;
    scanf("%lld", &amountq);
    while(amountq--) 
    {
        scanf("%lld %lld", &amount, &k);
        scanf("%lld", &fir);
        prev = fir;
        allsame = true;
        sorted = true;
        for(int i = 1; i < amount; i++)
        {
            scanf("%lld", &cur);
            if(cur != fir)
            {
                allsame = false;
            }
            if(prev > cur)
            {
                sorted = false;
            }
            prev = cur;
        }
        printf("%s\n", k > 1 || allsame || sorted ? "YES" : "NO");
    }
    return 0;
}
