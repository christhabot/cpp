#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int, int> mp;
// idx
vector<int> pref, vec;

int main() 
{
    freopen("sumoffew.in", "r", stdin);
    freopen("sumoffew.out", "w", stdout);
    int amount, dif, cur, best = 0, p;
    scanf("%d %d", &amount, &dif);
    vec.resize(amount);
    scanf("%d", &vec[0]);
    pref.assign(amount, 0);
    pref[0] = vec[0];
    for(int i = 1; i < amount; i++)
    {
        scanf("%d", &vec[i]);
        pref[i] = pref[i-1] + vec[i];
    }
    int l = 0;
    for(int r = 0; r < amount; r++)
    {
        if(mp.count(vec[r]))
        {
            mp[vec[r]]++;
        }
        else
        {
            mp.insert({vec[r], 1});
        }
        while(mp.size() > dif)
        {
            p = best;
            if(l == 0)
            {
                best = max(best, pref[r-1]);
            }
            else
            {
                best = max(best, pref[r-1] - pref[l-1]);
            }
            if(mp[vec[l]] > 1)
            {
                mp[vec[l]]--;
            }
            else
            {
                mp.erase(vec[l]);
            }
            l++;
        }
    }
    if(l == 0)
    {
        best = max(best, pref[amount-1]);
    }
    else
    {
        best = max(best, pref[amount-1] - pref[l-1]);
    }
    printf("%d\n", best);
}