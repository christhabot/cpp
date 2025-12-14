#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, x, y, z;
    bitset<32> ba, bb, bc;
    bool good;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld %lld", &x, &y, &z);
        bitset<32> bx(x), by(y), bz(z);
        bb = bx;
        bb |= by;

        bc = by;
        bc |= bz;

        ba = bx;
        ba |= bz;

        good = true;
        good &= (ba & bb) == bx;
        good &= (bb & bc) == by;
        good &= (bc & ba) == bz;

        printf("%s\n", good ? "YES" : "NO");
    }
}
