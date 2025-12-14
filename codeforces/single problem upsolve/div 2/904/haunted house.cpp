#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, amount;
    string str;
    scanf("%lld", &amountq);

    while(amountq--)
    {
        scanf("%lld", &amount);
        cin >> str;

        reverse(str.begin(), str.end());

        vector<int> pref(amount + 1, 0);
        for(int i = 1; i <= amount; i++)
            pref[i] = pref[i-1] + (str[i-1] == '1' ? 1 : 0);

        vector<int> zeros_pos;
        for(int i = 0; i < amount; ++i)
            if(str[i] == '0') zeros_pos.push_back(i);

        int total_zeros = (int)zeros_pos.size();

        vector<ll> zero_pref(total_zeros + 1, 0);
        for(int i = 0; i < total_zeros; ++i)
            zero_pref[i+1] = zero_pref[i] + (ll)zeros_pos[i];

        ll cnt = 0;            
        ll sum_one = 0;       
        int zero_idx = 0;     

        for(int i = 1; i <= amount; i++)
        {

            if(i > total_zeros)
            {
                printf("-1 ");

                if(str[i-1] == '1') { cnt++; sum_one += (i-1); }
                continue;
            }

            if(str[i-1] == '1') { cnt++; sum_one += (i-1); }

            while(zero_idx < total_zeros && zeros_pos[zero_idx] < i) zero_idx++;

            ll sum_zero = zero_pref[zero_idx + (int)cnt] - zero_pref[zero_idx];

            ll ops = sum_zero - sum_one;
            printf("%lld ", ops);
        }
        printf("\n");
    }
}