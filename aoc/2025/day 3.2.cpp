#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ll amountq, total = 0, big, prev;
    string str;
    scanf("%lld", &amountq);

    while(amountq--)
    {
        cin >> str;
        prev = -1;
        for(int i = 1; i <= 12; i++)
        {
            big = prev+1;
            for(int j = prev+2; j < str.size()-12+i; j++)
            {
                if(str[j] > str[big])
                {
                    big = j;
                }
            }
            prev = big;
            total += pow(10, (12-i)) * (str[big]-'0');
        }
    }

    cout << total;
}
