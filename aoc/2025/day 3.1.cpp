#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, total = 0, big, big2;
    string str;
    scanf("%lld", &amountq);

    while(amountq--)
    {
        cin >> str;
        big = 0;
        for(int i = 1; i < str.size()-1; i++)
        {
            if(str[i] > str[big])
            {
                big = i;
            }
        }
        big2 = big+1;
        for(int i = big+2; i < str.size(); i++)
        {
            if(str[i] > str[big2])
            {
                big2 = i;
            }
        }
        total += (str[big]-'0')*10+(str[big2]-'0');
    }

    cout << total;
}
