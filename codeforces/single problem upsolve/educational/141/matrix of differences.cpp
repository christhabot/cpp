#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

int main() 
{
    ll amountq, amount, sumeven, sumodd;
    bool odd;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.clear();
        for(int i = 0; i < amount*amount; i++)
        {
            vec.push_back(i % 2 ? i/2+1 : amount*amount-i/2);
        }

        for (int r = 0; r < amount; ++r) 
        {
            if (r % 2 == 0) 
            {
                for (int c = 0; c < amount; ++c) 
                {
                    printf("%lld ", vec[r*amount+c]);
                }
            } 
            else 
            {
                for (int c = amount - 1; c >= 0; --c) 
                {
                    printf("%lld ", vec[r*amount+c]);
                }
            }
            printf("\n");
        }
    }
}
