#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<pair<int,int>> used;

int main() {
    int amount, amountq, total = 0;
    scanf("%d %d", &amount, &amountq);

    while(amountq--) 
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; 
        b--;

        if(!used.count({a,b}) && !used.count({a,b+1}) && !used.count({a+1,b}) && !used.count({a+1,b+1})) 
        {
            total++;
            used.insert({a,b});
            used.insert({a,b+1});
            used.insert({a+1,b});
            used.insert({a+1,b+1});
        }
    }

    printf("%d\n", total);
}
