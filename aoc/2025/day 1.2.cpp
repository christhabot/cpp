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

        int dir = op ? 1 : -1;
        int dist = abs(num);

        for(int i = 0; i < dist; i++)
        {
            cur += dir;
            if(cur == 100) cur = 0;
            if(cur == -1)  cur = 99;

            if(cur == 0)
                total++;
        }
    }

    printf("%d\n", total);
}
