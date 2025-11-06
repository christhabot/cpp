#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }

        vector<ll> b(m), c(m);
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &b[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &c[i]);
        }

        vector<pair<ll, ll>> vec1;
        vector<ll> cons;
        for (int i = 0; i < m; i++)
        {
            if (c[i] > 0)
            {
                vec1.emplace_back(b[i], c[i]);
            }
            else
            {
                cons.push_back(b[i]);
            }
        }

        sort(vec1.begin(), vec1.end());
        sort(cons.begin(), cons.end());

        multiset<ll> vec2;
        for (auto x : a)
        {
            vec2.insert(x);
        }

        int killed = 0;

        for (auto p : vec1)
        {
            ll bb = p.first;
            ll cc = p.second;
            auto it = vec2.lower_bound(bb);
            if (it == vec2.end())
            {
                continue;
            }
            ll x = *it;
            vec2.erase(it);
            killed++;
            vec2.insert(max(x, cc));
        }

        for (auto bb : cons)
        {
            auto it = vec2.lower_bound(bb);
            if (it == vec2.end())
            {
                continue;
            }
            vec2.erase(it);
            killed++;
        }

        printf("%d\n", killed);
    }
}