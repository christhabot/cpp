#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll head, body;
    scanf("%lld %lld", &head, &body);
    printf("%lld", max(0ll, head - body));
}