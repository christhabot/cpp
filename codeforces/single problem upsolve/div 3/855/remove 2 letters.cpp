#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() 
{
    ll amountq, trash, res;
    string s;
    scanf("%lld", &amountq);
    while(amountq--)
    {
        scanf("%lld", &trash);
        cin >> s;
        res = trash - 1;
        for(int i = 1; i < s.size() - 1; i++)
        {
            if(s[i+1] == s[i-1])
                res--;
        }
        printf("%lld\n", res);
    }
}