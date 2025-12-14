#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec;
unordered_map<int, set<int>> st;

int main() 
{
    freopen("landfight.in", "r", stdin);
    freopen("landfight.out", "w", stdout);
    int amount, cur, curs, res;
    scanf("%d", &amount);
    vec.resize(amount);
    st.clear();
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &vec[i]);
    }
    cur = vec.back();
    st[cur].insert(amount-1);
    for(int i = amount-2; i >= 0; i--)
    {
        cur += vec[i];
        st[cur].insert(i);
        // cout << cur << " ";
    }
    // cout << "\n";
    st[0].insert(amount);
    cur = 0;
    res = *st[0].begin()+1;
    // cout << res << " ";
    for(int i = 0; i < amount; i++)
    {
        cur += vec[i];
        // cout << cur << " ";
        if(!st.count(cur))
            continue;
        // auto it = st[cur].end();
        // it--;
        auto it = st[cur].lower_bound(i);
        if(it == st[cur].end() || *it < i)
            continue;
        // res = min(res, amount - (i + amount - abs((int)distance(it, st[cur].end()))));
        // res = min(res, amount - (i + amount - *it));
        res = min(res, *it - i + 1);
        // cout << res << " ";
        // cout << *it << " ";
    }
    printf("%d\n", res);
}