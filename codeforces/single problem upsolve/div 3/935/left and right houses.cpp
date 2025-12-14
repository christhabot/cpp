#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> pref, suf;

int main() 
{
    int amountq, amount;
    string str;
    scanf("%d", &amountq);

    while(amountq--)
    {
        scanf("%d", &amount);
        cin >> str;

        pref.assign(amount, 0);
        suf.assign(amount, 0);

        pref[0] = (str[0] == '0');
        for(int i = 1; i < amount; i++)
            pref[i] = pref[i-1] + (str[i] == '0');

        suf[amount-1] = (str[amount-1] == '1');
        for(int i = amount-2; i >= 0; i--)
            suf[i] = suf[i+1] + (str[i] == '1');

        auto need = [&](int x){ return (x + 1) / 2; };

        int best = -1;
        int bestDist = INT_MAX;

        for(int i = 0; i <= amount; i++)
        {
            int left = i;
            int right = amount - i;

            int zerosLeft = (left == 0 ? 0 : pref[left - 1]);
            int onesRight = (right == 0 ? 0 : suf[i]);

            if(zerosLeft >= need(left) && onesRight >= need(right))
            {
                int dist = abs(2*i - amount);
                if(dist < bestDist)
                {
                    bestDist = dist;
                    best = i;
                }
            }
        }

        printf("%d\n", best);
    }
}
