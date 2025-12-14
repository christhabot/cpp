#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, n, m, num;
    ll i, j, res;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld %lld", &n, &m, &num);
        i = (num - 1) % n + 1;
        j = (num - 1) / n + 1;
        res = (i-1)*m + j;
        printf("%lld\n", res);
    }
}