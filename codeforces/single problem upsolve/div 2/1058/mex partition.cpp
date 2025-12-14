#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec;
vector<bool> found;

int main() 
{
    int amountq, amount, big;
    scanf("%d", &amountq);
    bool f;
    while(amountq--)
    {
        big = 0;
        scanf("%d", &amount);
        vec.resize(amount);
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &vec[i]);
            big = max(big, vec[i]);
        }
        found.assign(big+2, false);
        for(int i = 0; i < amount; i++)
        {
            found[vec[i]] = true;
        }
        f = false;
        for(int i = 0; i <= big+1 && !f; i++)
        {
            if(!found[i])
            {
                f = true;
                printf("%d\n", i);
            }
        }
    }
}