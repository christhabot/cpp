#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq, amount;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        vector<ll> vec(amount);
        for(int i = 0; i < amount; i++)
        {
            scanf("%lld", &vec[i]);
        }
        
        map<pair<int,int>, ll> dp;
        
        int mid = amount / 2;
        
        if(amount % 2 == 1) 
        {
            dp[{mid, 0}] = 0;
            dp[{mid, 1}] = 0;
        }
        else 
        {
            int left = mid - 1;
            int right = mid;
            ll cost = (vec[left] == vec[right]) ? 1 : 0;
            dp[{left, 0}] = cost;
            dp[{left, 1}] = cost;
        }
        
        int start = (amount % 2 == 1) ? mid - 1 : mid - 2;
        for(int i = start; i >= 0; i--)
        {
            int mirror = amount - i - 1;
            
            ll cost0 = (vec[i] == vec[i+1]) ? 1 : 0;
            cost0 += (vec[mirror] == vec[mirror-1]) ? 1 : 0;
            cost0 += dp[{i+1, 0}];
            
            ll cost1 = (vec[mirror] == vec[i+1]) ? 1 : 0;
            cost1 += (vec[i] == vec[mirror-1]) ? 1 : 0;
            cost1 += dp[{i+1, 1}];
            
            dp[{i, 0}] = min(cost0, cost1);
            dp[{i, 1}] = min(cost0, cost1);
        }
        
        printf("%lld\n", dp[{0, 0}]);
    }
}