#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec;

int main() 
{
    int amountq, amount;
    bool good;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        vec.resize(amount);
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &vec[i]);
        }
        sort(vec.begin(), vec.end());
        good = true;
        for(int i = 1; i < amount-1; i+= 2)
        {   
            if(vec[i] != vec[i+1])
            {
                good = false;
            }
        }
        if(good)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}