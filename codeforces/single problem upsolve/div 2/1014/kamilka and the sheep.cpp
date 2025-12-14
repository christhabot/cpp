#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, amount, big, small, temp;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        small = LLONG_MAX;
        big = LLONG_MIN;
        while(amount--)
        {
            scanf("%lld", &temp);
            big = max(temp, big);
            small = min(temp, small);
        }
        printf("%lld\n", big - small);
    }
}