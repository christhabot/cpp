#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec;

int main() 
{
    int amountq, amount, bigi, smalli;
    string str;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        vec.resize(amount);
        bigi = 0;
        smalli = 0;
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &vec[i]);
            if(vec[i] > vec[bigi])
            {
                bigi = i;
            }
            if(vec[i] < vec[smalli])
            {
                smalli = i;
            }
        }
        str.resize(amount);
        for(int i = 0; i < amount; i++)
        {
            scanf(" %c", &str[i]);
        }
        if(str[bigi] == '1' || str[smalli] == '1' || str[0] == '1' || str[amount-1] == '1')
        {
            printf("-1\n");
        }
        else
        {
            int ops = 0;
            ops += (bigi+1 != 1);
            ops += (smalli+1 != 1);
            ops += (bigi+1 != amount);
            ops += (smalli+1 != amount);
            ops++;

            printf("%d\n", ops);
            if(bigi+1 != 1)
                printf("1 %d\n", bigi+1);
            if(smalli+1 != 1)
                printf("1 %d\n", smalli+1);
            if(bigi+1 != amount)
                printf("%d %d\n", bigi+1, amount);
            if(smalli+1 != amount)
                printf("%d %d\n", smalli+1, amount);
            printf("1 %d\n", amount);
        }
    }
}