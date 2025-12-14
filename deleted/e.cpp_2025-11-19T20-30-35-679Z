#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<char> vec, vec2;
vector<char> nob1;

int main() 
{
    int amountq, amount, b1, b2, idx, found, pending;
    bool good;
    bool a, c;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        vec.resize(amount);
        vec2.resize(amount);
        nob1.clear();
        b1 = 0;
        b2 = 0;
        for(int i = 0; i < amount; i++)
        {
            scanf(" %c", &vec[i]);
            if(vec[i] == 'b')
            {
                b1++;
            }
            else
            {
                nob1.push_back(vec[i]);
            }
        }
        idx = 0;
        good = true;
        for(int i = 0; i < amount; i++)
        {
            scanf(" %c", &vec2[i]);
            if(vec2[i] == 'b')
            {
                b2++;
            }
            else
            {
                if(idx > (int)nob1.size() - 1 || vec2[i] != nob1[idx])
                {
                    good = false;
                }
                idx++;
            }
        }
        if(idx < nob1.size())
        {
            good = false;
        }
        found = 0;
        pending = 0;
        if(good)
        {
            for(int i = 0; i < amount; i++)
            {
                if(vec[i] == 'b')
                {
                    if(pending > 0)
                    {
                        pending--;
                    }
                    else
                    {
                        found++;
                    }
                }
                if(vec[i] == 'a')
                {
                    if(found > 0)
                    {
                        good = false;
                    }
                }
                if(vec2[i] == 'b')
                {
                    if(found > 0)
                    {
                        found--;
                    }
                    else
                    {
                        pending++;
                    }
                }
                
                if(vec[i] == 'c')
                {
                    if(pending > 0)
                    {
                        // cout << pending << " " << found;
                        good = false;
                    }
                }
            }
        }
        printf("%s", good ? "YES\n" : "NO\n");
    }
}