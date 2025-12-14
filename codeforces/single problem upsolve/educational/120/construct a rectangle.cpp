#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq;
    int a, b, c;
    bool can;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d %d", &a, &b, &c);
        can = false;
        can |= a == b && c % 2 == 0;
        can |= b == c && a % 2 == 0;
        can |= a == c && b % 2 == 0;
        can |= a == b + c;
        can |= b == a + c;
        can |= c == a + b;
        printf("%s\n", can ? "YES" : "NO");
    }
}