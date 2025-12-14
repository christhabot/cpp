#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int amountq, n, k;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d", &n, &k);
        printf("%d\n", (n - 1 + (k - 2)) / (k - 1));
    }
}
