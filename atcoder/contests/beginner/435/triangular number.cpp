#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    int amount, total = 0;
    scanf("%d", &amount);
    for(int i = 1; i <= amount; i++)
    {
        total += i;
    }
    printf("%d\n", total);
}