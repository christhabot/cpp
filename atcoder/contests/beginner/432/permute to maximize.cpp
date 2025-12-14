#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    vector<int> vec;
    vec.resize(3);
    scanf("%d %d %d", &vec[0], &vec[1], &vec[2]);
    sort(vec.begin(), vec.end());
    printf("%d%d%d", vec[2], vec[1], vec[0]);
}