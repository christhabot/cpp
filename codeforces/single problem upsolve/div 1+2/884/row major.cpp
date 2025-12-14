#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll amountq, amount, thing;
    string res;
    scanf("%lld", &amountq);
    while (amountq--) 
    {
        scanf("%lld", &amount);
        thing = 1;
        while(!(amount % thing)) 
        {
            thing++;
        }
        res.resize(amount);
        for(int i = 0; i < amount; i++) 
        {
            res[i] = (i % thing) + 'a';
        }
        cout << res << "\n";
    }
    return 0;
}