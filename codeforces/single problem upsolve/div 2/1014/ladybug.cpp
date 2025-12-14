#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq, amount;
    int oo, zo, ot, zt;
    char temp;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        oo = 0;
        zo = 0;
        ot = 0;
        zt = 0;
        for(int i = 0; i < amount; i++)
        {
            scanf(" %c", &temp);
            if(temp == '1')
            {
                if(i % 2 == 0)
                {
                    oo++;
                }
                else
                {
                    ot++;
                }
            }
        }
        for(int i = 0; i < amount; i++)
        {
            scanf(" %c", &temp);
            if(temp == '0')
            {
                if(i % 2 == 1)
                {
                    zo++;
                }
                else
                {
                    zt++;
                }
            }
        }
        // printf("%d %d %d %d ", oo, ot, zo, zt);
        printf("%s", oo <= zo && ot <= zt ? "YES\n" : "NO\n");
    }
}