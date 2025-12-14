#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    string str;
    string res;
    int amountq, amount, a, b, c;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        cin >> str;

        a = 0;
        b = 0;
        c = 0;

        for(int i = 0; i < amount/2; i++)
        {
            if(str[i] == str[amount - i - 1])
            {
                a++;
            }
            else
            {
                b++;
            }
        }

        res.assign(amount+1, '0');

        for(int i = 0; i <= a; i++)
        {
            c = b + 2*i;
            if(c <= amount)
            {
                res[c] = '1';
            }
            if(amount % 2)
            {
                if(c+1<=amount)
                {
                    res[c+1] = '1';
                }
            }
        }
        cout << res << "\n";
    }
}
