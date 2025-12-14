#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_multimap<ll, ll> mp;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() 
{
    ll amountq, days, last, tasks, l, r, cur, small, big, bigi, smalli;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        mp.clear();
        scanf("%lld %lld %lld", &days, &last, &tasks);
        for(int i = 0; i < tasks; i++)
        {
            scanf("%lld %lld", &l, &r);
            l--; r--;
            mp.insert({l, r});
        }

        while(!pq.empty()) pq.pop();
        cur = 0;

        big = LLONG_MIN;
        small = LLONG_MAX;

        int maxStart = (int)(days - last);

        if (maxStart < 0) {

            printf("1 1\n\n");
            continue;
        }

        ll endd = last - 1;

        for (ll addL = 0; addL <= endd; ++addL)
        {
            auto range = mp.equal_range(addL);
            for (auto it = range.first; it != range.second; ++it)
            {
                pq.push(it->second);
                cur++;
            }
        }

        for(int s = 0; s <= maxStart; s++)
        {

            if (s > 0)
            {
                endd = s + last - 1;
                auto range = mp.equal_range(endd);
                for (auto it = range.first; it != range.second; ++it)
                {
                    pq.push(it->second);
                    cur++;
                }
            }

            while(!pq.empty() && pq.top() < s)
            {
                pq.pop();
                cur--;
            }

            if(cur > big)
            {
                big = cur;
                bigi = s;
            }
            if(cur < small)
            {
                small = cur;
                smalli = s;
            }
        }

        printf("%lld %lld\n", bigi + 1, smalli + 1);
    }
    return 0;
}