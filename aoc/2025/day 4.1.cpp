#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<bool>> vec;

int main() 
{
    ll amount, curt, total = 0;
    char cur;
    bool no;
    scanf("%lld", &amount);

    vec.assign(amount, vector<bool>(amount, false));
    for(int i = 0; i < amount; i++)
    {
        for(int j = 0; j < amount; j++)
        {
            scanf(" %c", &cur);
            if(cur == '@')
            {
                vec[i][j] = true;
            }
        }
    }

    for(int i = 0; i < amount; i++)
    {
        for(int j = 0; j < amount; j++)
        {
            if(vec[i][j])
            {
                curt = 0;
                for(int i1 = -1; i1 <= 1; i1++)
                {
                    for(int j1 = -1; j1 <= 1; j1++)
                    {
                        no = false;
                        if(i1 == 0 && j1 == 0) no = true;
                        if(i + i1 < 0 || i + i1 >= amount) no = true;
                        if(j + j1 < 0 || j + j1 >= amount) no = true;
                        if(!no && vec[i+i1][j+j1]) curt++;
                    }
                }
                if(curt < 4)
                {
                    total++;
                }
            }
        }
    }

    cout << total;
}
