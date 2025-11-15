#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amountq;
    int j, k;
    scanf("%d", &amountq);
    for(int i = 0; i < amountq; i++)
    {
        scanf("%d %d", &j, &k);
        int y = j;
        while (true) 
        {
            int tmp = 0;
            for(char e : to_string(y)) tmp += e - '0';
            if(tmp % k == 0) 
            {
                printf("%d\n", y);
                break;
            }
            y++;
        }
    }
}
