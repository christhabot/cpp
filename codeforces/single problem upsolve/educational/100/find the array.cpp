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
        vec.resize(amount);
        sumodd = 0;
        sumeven = 0;
        for(ll i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
            if(i % 2 == 1)
            {
                sumodd += vec[i]-1;
            }
            else
            {
                sumeven += vec[i]-1;
            }
        }
        // cout << sumodd << " " << sumeven << "\n";
        odd = sumodd <= sumeven;
        for(ll i = 0; i < amount; i++)
        {
            if((i % 2 == 1) == odd)
            {
                printf("1 ");
            }
            else
            {
                printf("%lld ", vec[i]);
            }
        }
        printf("\n");
    }
}
