#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec, whatis;

int main() 
{
    ll amountq, amount, ops, k, op, l, r;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld %lld", &amount, &k, &ops);

        vector<pair<ll,ll>> op2ranges;

        vector<ll> diff1(amount + 1, 0);
        vector<ll> diff2(amount + 1, 0);

        for(ll i = 0; i < ops; i++)
        {
            scanf("%lld %lld %lld", &op, &l, &r);
            l--;
            r--;

            if(op == 1)
            {
                diff1[l]++;
                diff1[r + 1]--;
            }
            else if(op == 2)
            {
                diff2[l]++;
                diff2[r + 1]--;
                op2ranges.push_back({l, r});
            }
        }

        whatis.assign(amount, 0);
        vec.assign(amount, -1);
        int count1 = 0, count2 = 0;
        for(ll i = 0; i < amount; i++)
        {
            count1 += diff1[i];
            count2 += diff2[i];

            if(count1 > 0 && count2 > 0) whatis[i] = 3;
            else if(count2 > 0) whatis[i] = 2;
            else if(count1 > 0) whatis[i] = 1;
            else whatis[i] = 0;

            if(whatis[i] == 3)
            {
                vec[i] = k+1;
            }
            else if(whatis[i] == 1)
            {
                vec[i] = k;
            }
            else if(whatis[i] == 0)
            {
                vec[i] = 0;
            }
        }

        vector<set<ll>> rangeNeeds(op2ranges.size());
        for(ll idx = 0; idx < (ll)op2ranges.size(); idx++)
        {
            for(ll v = 0; v < k; v++)
            {
                rangeNeeds[idx].insert(v);
            }
        }

        vector<vector<ll>> coveringRanges(amount);
        for(ll idx = 0; idx < (ll)op2ranges.size(); idx++)
        {
            for(ll i = op2ranges[idx].first; i <= op2ranges[idx].second; i++)
            {
                coveringRanges[i].push_back(idx);
            }
        }

        for(ll i = 0; i < amount; i++)
        {
            if(whatis[i] == 2 && vec[i] == -1)
            {

                ll bestIdx = -1;
                ll minRemaining = LLONG_MAX;
                ll bestVal = -1;

                for(ll idx : coveringRanges[i])
                {
                    if(!rangeNeeds[idx].empty())
                    {
                        ll remaining = op2ranges[idx].second - i;
                        ll val = *rangeNeeds[idx].begin();

                        if(bestIdx == -1 || remaining < minRemaining || 
                           (remaining == minRemaining && val < bestVal))
                        {
                            bestIdx = idx;
                            minRemaining = remaining;
                            bestVal = val;
                        }
                    }
                }

                if(bestIdx != -1)
                {
                    vec[i] = bestVal;

                    for(ll idx : coveringRanges[i])
                    {
                        rangeNeeds[idx].erase(bestVal);
                    }
                }
            }
        }

        for(ll i = 0; i < amount; i++)
        {
            printf("%lld ", vec[i] == -1 ? k+1 : vec[i]);
        }
        printf("\n");
    }

    return 0;
}