#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prefraw;
unordered_set<int> st;

int main() 
{   
    // freopen("intvsum.in", "r", stdin);
    // freopen("intvsum.out", "w", stdout);
    int amount, found = -1, cur;
    scanf("%d", &amount);
    scanf("%d", &cur);
    prefraw.resize(amount);
    prefraw[0] = cur;
    st.insert(0 - cur);
    for(int i = 1; i < amount; i++)
    {
        scanf("%d", &cur);
        prefraw[i] = prefraw[i-1] + cur;
        if(st.count(prefraw[i-1] - cur))
        {
            found = i;
        }
        st.insert(cur + prefraw[i]);
    }
    printf("%d\n", found+1);
}