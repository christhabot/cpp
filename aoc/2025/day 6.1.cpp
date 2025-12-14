#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> vec1, vec2, vec3, vec4;
vector<char> ops;

int main() 
{
    int amount;
    char op;
    ll total = 0;
    scanf("%d", &amount);

    vec1.resize(amount);
    vec2.resize(amount);
    vec3.resize(amount);
    vec4.resize(amount);
    ops.resize(amount);

    for(int i = 0; i < amount; i++)
        scanf("%lld", &vec1[i]);

    for(int i = 0; i < amount; i++)
        scanf("%lld", &vec2[i]);

    for(int i = 0; i < amount; i++)
        scanf("%lld", &vec3[i]);

    for(int i = 0; i < amount; i++)
        scanf("%lld", &vec4[i]);   // ⭐ new row

    for(int i = 0; i < amount; i++)
    {
        scanf(" %c", &op);
        ops[i] = op;               // ⭐ store op per-problem
    }

    for(int i = 0; i < amount; i++)
    {
        if(ops[i] == '+')
            total += vec1[i] + vec2[i] + vec3[i] + vec4[i];
        else
            total += vec1[i] * vec2[i] * vec3[i] * vec4[i];
    }

    cout << total;
}
