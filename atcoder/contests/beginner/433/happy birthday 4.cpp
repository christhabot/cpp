#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll X, Y, Z;
    scanf("%lld %lld %lld", &X, &Y, &Z);
    while(X > Y*Z)
    {
        X++;
        Y++;
    }
    printf("%s\n", X == Y*Z ? "Yes" : "No");
}