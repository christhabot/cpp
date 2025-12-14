#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, l, r, total = 0;
    string str, str2;
    scanf("%lld", &amountq);

    while(amountq--)
    {
        scanf("%lld %lld", &l, &r);
        for(ll i = l; i <= r; i++)
        {
            str = to_string(i);
            str2.clear();

            for(int j = 1; j < (int)str.size(); j++)
            {
                str2.push_back(str[j]);
            }

            for(int j = 0; j < (int)str.size() - 1; j++)
            {
                str2.push_back(str[j]);
            }

            if(str2.find(str) != string::npos)
            {
                total += i;
            }
        }
    }

    cout << total;
}
