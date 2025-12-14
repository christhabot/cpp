#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec;
vector<int> cnt;

int main() 
{
    int amountq, small;
    string str;
    scanf("%d", &amountq);
    while(amountq--)
    {
        cin >> str;
        small = 9;
        cnt.assign(10, 0);
        for(int i = str.size()-1; i >= 0; i--)
        {
            if(str[i] - '0' > small)
            {
                cnt[min(str[i]-'0'+1, 9)]++;
            }
            else
            {
                small = str[i]-'0';
                cnt[str[i]-'0']++;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < cnt[i]; j++)
            {
                printf("%d", i);
            }
        }
        printf("\n");
    }
}