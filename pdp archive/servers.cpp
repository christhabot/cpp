#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<int,int>> vec;

int main() 
{   
    int pages, servers, wanted, num, amount;
    scanf("%d %d %d", &pages, &servers, &wanted);
    vec.assign(pages, {0, 0});
    for(int i = 0; i < pages*servers; i++)
    {
        scanf("%d %d", &num, &amount);
        vec[num] = {vec[num].first+amount, num};
    }
    sort(vec.begin(), vec.end(), greater<pair<int,int>>());
    for(int i = 0; i < wanted; i++)
    {
        printf("%d %d\n", vec[i].second, vec[i].first);
    }
}