#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> pref;
unordered_map<int, int> last;

int main() 
{   
    freopen("maxzero.in", "r", stdin);
    freopen("maxzero.out", "w", stdout);
    int amount, temp, best = 0;
    scanf("%d", &amount);
    pref.resize(amount);
    scanf("%d", &pref[0]);
    last.insert({pref[0], 0});
    for(int i = 1; i < amount; i++)
    {
        scanf("%d", &temp);
        pref[i] = pref[i-1] + temp;
        if(!last.count(pref[i]))
        {
            last.insert({pref[i], i});
        }
    }
    for(int i = 0; i < amount; i++)
    {
        if(last.count(pref[i]))
        {
            // cout << pref[i] << " " << last[pref[i]] << "\n";
            best = max(best, abs(last[pref[i]] - i));
        }
        else if(pref[i] == 0)
        {
            best = max(best, i);
        }
    }
    printf("%d\n", best);
}