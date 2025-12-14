#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amount, num, cur, total = 0;
    bool op; // l = false, r = true
    string s; 
    scanf("%d", &amount);
    cur = 50;
    while(amount--)
    {
        cin >> s;
        op = s[0] == 'R';
        num = stoi(s.substr(1));
        if(!op)
        {
            num *= -1;
        }
        cur = (((cur+num) % 100) + 100) % 100;
        if(cur == 0)
        {
            total++;
        }
    }
    printf("%d\n", total);
}