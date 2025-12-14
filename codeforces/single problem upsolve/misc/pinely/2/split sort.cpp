#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> pos;

int main() 
{
    int amountq, amount, cur, total;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        pos.resize(amount);
        total = 0;
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &cur);
            cur--;
            pos[cur] = i;
        }
        for(int i = 1; i < amount; i++)
        {
            if(pos[i] < pos[i-1])
            {
                total++;
            }
            else
            {
                // cout << pos[i] << " " << pos[i-1] << " ";
            }
        }
        printf("%d\n", total);
    }
}