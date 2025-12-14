#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int amountq;
    cin >> amountq;
    
    while(amountq--)
    {
        int amount;
        cin >> amount;
        
        vector<int> vec(amount);
        vector<int> res(amount);
        vector<pair<int,int>> liked, disliked;
        
        for(int i = 0; i < amount; i++)
        {
            cin >> vec[i];
        }
        
        string s;
        cin >> s;

        for(int i = 0; i < amount; i++)
        {
            if(s[i] == '0')
            {
                disliked.push_back({vec[i], i});
            }
            else
            {
                liked.push_back({vec[i], i});
            }
        }

        sort(disliked.begin(), disliked.end());
        sort(liked.begin(), liked.end());

        for(int i = 0; i < (int)disliked.size(); i++)
        {
            res[disliked[i].second] = i+1;
        }
        for(int i = 0; i < (int)liked.size(); i++)
        {
            res[liked[i].second] = (int)disliked.size() + i + 1;
        }

        for(int i = 0; i < amount; i++)
        {
            cout << res[i];
            if(i < amount-1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}