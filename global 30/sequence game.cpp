#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq;
    cin >> amountq;
    while(amountq--) 
    {
        int amount;
        cin >> amount;
        vector<ll> vec(amount);
        for(int i = 0; i < amount; i++) 
        {
            cin >> vec[i];
        }
        ll x;
        cin >> x;
        
        vector<vector<pair<ll, ll>>> dp(amount, vector<pair<ll, ll>>(amount));
        
        for(int i = 0; i < amount; i++) 
        {
            dp[i][i] = {vec[i], vec[i]};
        }
        
        for(int len = 2; len <= amount; len++) 
        {
            for(int i = 0; i <= amount - len; i++) 
            {
                int j = i + len - 1;
                ll min_val = LLONG_MAX;
                ll max_val = LLONG_MIN;
                
                for(int k = i; k < j; k++) 
                {
                    ll left_min = dp[i][k].first;
                    ll left_max = dp[i][k].second;
                    ll right_min = dp[k + 1][j].first;
                    ll right_max = dp[k + 1][j].second;
                    
                    ll merge_min = min(left_min, right_min);
                    ll merge_max = max(left_max, right_max);
                    
                    min_val = min(min_val, merge_min);
                    max_val = max(max_val, merge_max);
                }
                
                dp[i][j] = {min_val, max_val};
            }
        }
        
        ll final_min = dp[0][amount - 1].first;
        ll final_max = dp[0][amount - 1].second;
        
        if(final_min <= x && x <= final_max) 
        {
            cout << "YES\n";
        } 
        else 
        {
            cout << "NO\n";
        }
    }
}