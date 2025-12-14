#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec1;

int main() 
{
    freopen("twingift.in", "r", stdin);
    freopen("twingift.out", "w", stdout);
    int amount1, amount2, l, r, cur, bnd1, bnd2, total = 0;
    scanf("%d %d %d %d", &amount1, &amount2, &l, &r);
    vec1.resize(amount1);
    for(int i = 0; i < amount1; i++)
    {
        scanf("%d", &vec1[i]);
    }
    sort(vec1.begin(), vec1.end());
    for(int i = 0; i < amount2; i++)
    {
        scanf("%d", &cur);
        if(cur > r)
            continue;
        bnd1 = max(0, l - cur);
        bnd2 = r - cur;
        auto opt1 = lower_bound(vec1.begin(), vec1.end(), bnd1);
        auto opt2 = upper_bound(vec1.begin(), vec1.end(), bnd2);
        opt2--;
        if(cur + *opt1 > r || cur + *opt2 < l)
            continue;
        total += distance(opt1, opt2) + 1;
    }
    printf("%d\n", total);
}