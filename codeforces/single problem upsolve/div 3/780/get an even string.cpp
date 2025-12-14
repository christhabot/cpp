#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int maxPairs(string s) 
{
    bool prev[26] = {false};
    int m = 0;
    
    for (int i = 0; i < s.size(); i++) 
    {
        int idx = s[i] - 'a';
        if (!prev[idx]) 
        {
            prev[idx] = true;
        } 
        else 
        {
            m += 2;
            memset(prev, false, sizeof(prev));
        }
    }
    
    return s.size() - m;
}

int main() 
{
    ll amountq, erased, prevsize;
    string s;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        cin >> s;
        erased = maxPairs(s);
        printf("%lld\n", erased);
    }
}