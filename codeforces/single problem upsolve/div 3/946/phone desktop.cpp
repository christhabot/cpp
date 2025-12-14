#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq, big, small, neededbig, empty;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d", &small, &big);
        neededbig = (big + 1) / 2;
        empty = neededbig * 7;
        if(big % 2 == 1)
            empty += 4;
        small -= empty;
        small = max(0, small);
        printf("%d\n", neededbig + (small + 14) / 15);
    }
}