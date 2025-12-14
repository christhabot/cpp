#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll x, y, tile;
    cin >> x >> y >> tile;
    cout << ((x+tile-1)/tile) * ((y+tile-1)/tile);
}
