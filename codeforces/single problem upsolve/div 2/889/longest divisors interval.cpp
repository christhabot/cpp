#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() 
{
    ll amountq, num, idx, res;
    bool yes;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &num);
        yes = true;
        res = 1;
        idx = 2;
        while(yes)
        {
            if(num % idx != 0)
            {
                yes = false;
            }
            else
            {
                idx++;
                res++;
            }
        }
        printf("%lld\n", res);
    }
}