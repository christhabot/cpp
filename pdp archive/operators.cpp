#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec;
set<ll> st;

int main() 
{
    freopen("operators.in", "r", stdin);
    freopen("operators.out", "w", stdout);
    int amount, cur, best = INT_MAX, optimal, bestcur, best1 = -1, best2 = -1;
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &cur);
        st.insert(cur);
        vec.push_back(cur);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < amount; i++)
    {
        cur = vec[i];
        optimal = vec[i] * -1;
        st.erase(vec[i]);
        auto first = st.lower_bound(optimal);
        auto second = prev(st.lower_bound(optimal));
        if(first == st.end())
        {
            first--;
            first--;
        }
        if(second == st.end())
        {
            second--;
            second--;
        }
        if(abs(optimal - *first) < best)
        {
            best = abs(optimal - *first);
            best1 = cur;
            best2 = *first;
        }
        if(abs(optimal - *second) < best)
        {
            best = abs(optimal - *second); 
            best1 = cur;
            best2 = *second;
        }
        st.insert(vec[i]);
    }
    printf("%d %d\n", best1, best2);
}