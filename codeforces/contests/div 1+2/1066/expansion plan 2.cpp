#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, amount, x, y;
    char str[200005];
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld %lld", &amount, &x, &y);
        scanf("%s", str);
        
        ll ax = abs(x);
        ll ay = abs(y);
        
        for(ll i = 0; i < amount; i++)
        {
            if(str[i] == '4')
            {
                if(ay > 0)
                {
                    ay--;
                }
                else if(ax > 0)
                {
                    ax--;
                }
            }
            else
            {
                if(ax > 0 && ay > 0)
                {
                    ax--;
                    ay--;
                }
                else if(ax > 0)
                {
                    ax--;
                }
                else if(ay > 0)
                {
                    ay--;
                }
            }
        }
        
        if(ax == 0 && ay == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}