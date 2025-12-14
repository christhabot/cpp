#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int amount, cur, next = 1, i;
    cin >> amount;
    for(i = 0; i < amount && next > 0; i++)
    {
        cin >> cur;
        cur--;
        next--;
        next = max(next, cur);
    }

    printf("%d\n", i);
    return 0;
}
