#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq;
    ll b1, b2, a1, a2;
    bool f1, f2;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld %lld %lld", &b1, &b2, &a1, &a2);
        f1 = b1 <= b2;
        f2 = a1 <= a2;
        if(f1 == f2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}