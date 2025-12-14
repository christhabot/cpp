#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int amount, amountq;
vector<int> vec;
vector<vector<int>> sparse;

void build()
{
    for(int i = 0; i < amount; i++) 
    {
        sparse[i][0] = vec[i];
    }
    for(int i = 1; i <= (int)floor(log2(amount)); i++)
    {
        for(int j = 0; j + (1 << i) - 1 < amount; j++)
        {
            sparse[j][i] = min(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int query(int l, int r){
    int temp = (int)floor(log2(1 + r - l));
    return min(sparse[l][temp], sparse[r- (1 << temp) + 1][temp]);
}

int main()
{
    int l, r;
    scanf("%d", &amount);
    sparse.assign(amount, vector<int>((int)floor(log2(amount)) + 1));
    vec.resize(amount);
    for(int i = 0; i < amount; i++)
    {
        scanf("%d", &vec[i]);
    }
    build();
    scanf("%d", &amountq);
    while(amountq--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    }
}
