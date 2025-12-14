#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll amount;

ll cell(int i, int j)
{
    ll res = 0;
    res += i * amount;
    res += j + 1;
    return res;
}


int main() 
{
    ll amountq, cur, best = 0;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        best = 0;
        scanf("%lld", &amount);
        for(int i = 0; i < amount; i++)
        {
            for(int j = 0; j < amount; j++)
            {
                cur = cell(i, j);
                if(i > 0)
                {
                    cur += cell(i-1, j);
                }
                if(i < amount-1)
                {
                    cur += cell(i+1, j);
                }
                if(j > 0)
                {
                    cur += cell(i, j-1);
                }
                if(j < amount-1)
                {
                    cur += cell(i, j+1);
                }
                best = max(best, cur);
            }
        }
        printf("%lld\n", best);
    }
}