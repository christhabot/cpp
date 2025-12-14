#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq, num, times;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d", &num, &times);
        printf("%d\n", times % 2 == 0 ? 0 : num);
    }
}