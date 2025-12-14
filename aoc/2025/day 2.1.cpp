#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, l, r, total = 0;
    string str, strs1, strs2;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld %lld", &l, &r);
        for(ll i = l; i <= r; i++)
        {
            str = to_string(i);
            strs1 = "";
            strs2 = "";
            if(str.size() % 2)
            {
                continue;
            }
            for(int j = 0; j < str.size()/2; j++)
            {
                strs1 += str[j];
            }
            for(int j = str.size()/2; j < str.size(); j++)
            {
                strs2 += str[j];
            }
            if(strs1 == strs2)
            {
                total += i;
            }
        }
    }
    cout << total;
}