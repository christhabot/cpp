#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    string num;
    vector<int> vec;
    cin >> num;
    vec.assign(10, 0);
    for(int i = 0; i < num.size(); i++)
    {
        vec[num[i] - '0']++;
    }
    for(int j = 1; j < 10; j++)
    {
        if(vec[j] > 0)
        {
            vec[j]--;
            printf("%d", j);
            break;
        }
    }
    for(int i = 0; i < num.size(); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(vec[j] > 0)
            {
                vec[j]--;
                printf("%d", j);
                break;
            }
        }
    }
}