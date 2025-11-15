#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int, int> first_index;
vector<int> vec;

int main() 
{
    int amount;
    scanf("%d", &amount);
    vec.resize(amount);
    for (int i = 0; i < amount; i++) 
        scanf("%d", &vec[i]);

    int diff = 0;
    int best = 0;
    first_index[0] = -1;

    for (int i = 0; i < amount; i++) 
    {
        if (vec[i] % 2 == 0) diff--;
        else diff++;

        if (first_index.count(diff))
            best = max(best, i - first_index[diff]);
        else
            first_index[diff] = i;
    }

    printf("%d\n", best);
}
