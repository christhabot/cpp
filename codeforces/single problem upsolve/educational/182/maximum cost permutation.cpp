#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> vec;
unordered_set<int> ust;
set<int> st;
queue<int> q;

int main() 
{
    int amountq, amount, f, l, r;
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d", &amount);
        vec.resize(amount);
        st.clear();
        ust.clear();
        for(int i = 0; i < amount; i++)
        {
            scanf("%d", &vec[i]);
            if(vec[i] != 0)
            {
                ust.insert(vec[i]);
            }
            else
            {
                q.push(i);
            }
        }
        for(int i = 1; i <= amount; i++)
        {
            if(!ust.count(i))
                st.insert(i);
        }
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            vec[f] = *st.rbegin();
            st.erase(next(st.rbegin()).base());
        }
        l = -1;
        r = -1;
        for(int i = 0; i < amount; i++)
        {
            if(vec[i] != i+1)
            {
                if(l == -1)
                {
                    l = i;
                }
                r = i;
            }
        }
        if(l == -1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", r - l + 1);
        }
    }
}
