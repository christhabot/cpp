#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll,ll>> vec, vec2;

int main() 
{
    ll amount, amountq, total = 0, start, end;
    bool found;
    scanf("%lld", &amount);
    vec.resize(amount);
    for(int i = 0; i < amount; i++)
    {
        scanf("%lld %lld", &vec[i].first, &vec[i].second);
    }
    sort(vec.begin(), vec.end());
    start = vec[0].first;
    end = vec[0].second;

    for(int i = 1; i < amount; i++)
    {
        if(vec[i].first > end) {
            // no overlap → push
            vec2.push_back({start, end});
            start = vec[i].first;
            end = vec[i].second;
        } else {
            // overlap → merge
            end = max(end, vec[i].second);
        }
    }

    vec2.push_back({start, end});

    for(auto p : vec2)
    {
        cout << p.first << " " << p.second << "\n";
        total += p.second - p.first + 1;
    }
    cout << total;
}