#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> vec;

int main() 
{
    ll amountq, amount, cur;
    bool possible;
    scanf("%lld", &amountq);
    while (amountq--) 
    {
        scanf("%lld", &amount);
        scanf("%lld", &cur);
        cur--;
        possible = true;
        vec.clear();
        vec.assign(amount, false);
        vec[cur] = true;
        for(ll i = 1; i < amount; i++)
        {
            scanf("%lld", &cur);
            cur--;
            if(!(((cur > 0) && vec[cur-1]) || ((cur < amount-1) && vec[cur+1])))
            {
                possible = false;
            }
            vec[cur] = true;
        }
        printf("%s\n", possible ? "YES" : "NO");
    }
    return 0;
}