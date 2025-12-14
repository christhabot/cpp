#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;

int main() {
    ll amountq;
    scanf("%lld", &amountq);
    while (amountq--) {
        ll amount;
        scanf("%lld", &amount);
        vec.resize(amount);
        for (ll i = 0; i < amount; i++) scanf("%lld", &vec[i]);
        
        sort(vec.begin(), vec.end());
        
        ll big = 0;
        bool possible = true;
        for (ll i = 0; i < amount; i += 2) 
        {
            if (max(vec[i], big) != max(vec[i + 1], big)) 
            {
                possible = false;
                break;
            }
            big = max(big, vec[i]) + 1;
        }
        
        printf("%s\n", possible ? "Yes" : "No");
    }
}
