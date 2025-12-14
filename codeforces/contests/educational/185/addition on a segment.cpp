#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec;

int main() 
{
    ll amountq, amount, sum, nonzero;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.resize(amount);
        sum = 0;
        nonzero = 0;
        for(int i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
            sum += vec[i];
            if(vec[i] != 0)
            {
                nonzero++;
            }
        }
        printf("%lld\n", min(sum - amount + 1, nonzero));
    }
}