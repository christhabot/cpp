#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() 
{
    int amountq, amount, a, b;
    bool good;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d %d", &amount, &a, &b);
        good = false;
        good |= a <= b && amount % 2 == b % 2;
        good |= a > b && amount % 2 == a % 2 && amount % 2 == b % 2;
        printf("%s\n", good ? "YES" : "NO");
    }
}