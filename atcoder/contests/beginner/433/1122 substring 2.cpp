#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    string str;
    cin >> str;

    ll n = str.size();
    ll total = 0;

    ll row1 = 1;
    ll row2 = 0;

    bool matching = false;

    for (int i = 1; i < n; i++) 
    {
        if (!matching) 
        {
            if (str[i] == str[i - 1]) 
            {
                row1++;
            } 
            else 
            {
                if ((str[i] - '0') == (str[i - 1] - '0') + 1) 
                {
                    matching = true;
                    row2 = 1;
                } 
                else 
                {
                    row1 = 1;
                    row2 = 0;
                    matching = false;
                }
            }
        } 
        else 
        {
            if (str[i] == str[i - 1]) 
            {
                row2++;
            } 
            else 
            {
                total += min(row1, row2);

                if ((str[i] - '0') == (str[i - 1] - '0') + 1) 
                {
                    row1 = row2;
                    row2 = 1;
                    matching = true;
                } 
                else 
                {
                    row1 = 1;
                    row2 = 0;
                    matching = false;
                }
            }
        }
    }

    if (matching) total += min(row1, row2);
    printf("%lld", total);
}
