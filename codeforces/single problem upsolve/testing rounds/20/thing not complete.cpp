#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq, amount, cur;
    int res, l, r, mid, ql, qr, inp;
    string run;
    cin >> run;
    cin >> amountq;
    if(run == "first")
    {
        while(amountq--)
        {
            cin >> amount;
            res = -1;
            for(int i = 0; i < amount; i++)
            {
                cin >> cur;
                if(cur == 1 && res == -1)
                {
                    res = 0;
                }
                else if(cur == amount && res == -1)
                {
                    res = 1;
                }
            }
            cout << res << "\n";
        }
    }
    else
    {
        while(amountq--)
        {
            cin >> amount >> res;
            l = 0;
            r = (amount+1)/2;
            while(l < r)
            {
                mid = (l+r) / 2;
                ql = mid;
                qr = amount - mid + 1;
                printf("? %d %d\n", ql, qr);
                fflush(stdout);
                cin >> inp;
                if(inp == amount-1)
                {
                    l = mid;
                }
                else
                {
                    r = mid-1;
                }
            }
            printf("! %d\n", l);
        }
    }
}