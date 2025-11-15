#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vec(3);

int main() 
{
    int amountq;
    scanf("%d", &amountq);
    for(int i = 0; i < amountq; i++)
    {
        scanf("%d %d %d", &vec[0], &vec[1], &vec[2]);
        sort(vec.begin(), vec.end());
        printf("%d\n", vec[1] - vec[0] + vec[2] - vec[1]);
    }
}