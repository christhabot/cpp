#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq, amount, sum, temp;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        sum = 0;
        while(amount--)
        {
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%s\n", sum % 2 ? "NO" : "YES");
    }
}