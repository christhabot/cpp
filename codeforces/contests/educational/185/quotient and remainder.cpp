#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec1, vec2;
vector<ll> r;
multiset<ll> st;

int main()
{
    ll amountq;
    scanf("%lld", &amountq);

    while (amountq--)
    {
        ll amount, k;
        scanf("%lld %lld", &amount, &k);

        vec1.resize(amount);
        vec2.resize(amount);

        for (int i = 0; i < amount; i++)
            scanf("%lld", &vec1[i]);

        st.clear();
        for (int i = 0; i < amount; i++)
        {
            scanf("%lld", &vec2[i]);
            st.insert(vec2[i]);
        }

        r.clear();
        r.reserve(amount);

        for (int i = 0; i < amount; i++)
        {
            ll a = vec1[i];
            if (a > k) continue;
            ll B = (k - a) / (a + 1);
            if (B >= 1) r.push_back(B);
        }

        sort(r.begin(), r.end());

        ll answer = 0;
        for (size_t i = 0; i < r.size(); i++)
        {
            ll B = r[i];
            auto it = st.upper_bound(B);
            if (it == st.begin()) continue;
            it--;
            st.erase(it);
            answer++;
        }

        printf("%lld\n", answer);
    }
    return 0;
}