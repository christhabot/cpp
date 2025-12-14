#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> primes, vec;

int main()
{
    ll amountq, amount, nex, nexp;
    bool threes;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &amount);
        vec.clear();
        nex = 2;
        primes.clear();
        for(int i = 1; i <= amount; i++)
        {
            if(i % 2 != 0 && i % 3 != 0)
            {
                primes.push_back(i);
            }
        }
        threes = false;
        nexp = 0;
        for(int i = 0; i < amount; i++)
        {
            if(((i + 1) % 3 == 0 && (i+1) / 3 - 1 < primes.size()) || (threes && nex > amount))
            {
                vec.push_back(primes[nexp]);
                nexp++;
            }
            else if(!threes)
            {
                vec.push_back(nex);
                nex += 2;
                if(nex > amount)
                {
                    threes = true;
                    nex = 3;
                }
            }
            else
            {
                vec.push_back(nex);
                nex += 6;
            }
            printf("%lld ", vec[i]);
        }
        printf("\n");
    }
}
