#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int,int> freq;
vector<int> vec;

int main() 
{
    int amount, temp;
    scanf("%d", &amount);
    vec.resize(amount);
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &vec[i]);
    }

    for(int i = 0; i < amount-1; i++)
    {
        scanf("%d", &temp);
        freq[temp]++;
    }
    for(int i = 0; i < amount; i++)
    {
        if(freq[vec[i]] == 0)
        {
            printf("%d\n", vec[i]);
            vec.erase(vec.begin() + i);
            i = amount;
        }
        else
        {
            freq[vec[i]]--;
        }
    }

    freq.clear();
    for(int i = 0; i < amount-2; i++)
    {
        scanf("%d", &temp);
        freq[temp]++;
    }
    for(int i = 0; i < amount-1; i++)
    {
        if(freq[vec[i]] == 0)
        {
            printf("%d\n", vec[i]);
            vec.erase(vec.begin() + i);
            i = amount;
        }
        else
        {
            freq[vec[i]]--;
        }
    }
}
