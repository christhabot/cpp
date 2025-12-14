#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int amountq, amount, sum;
    cin >> amountq;
    
    while(amountq--) 
    {
        
        cin >> amount >> sum;

        if((sum % 2 == 1 && amount % 2 == 0) || sum < amount)
        {
            cout << "NO\n";
        } 
        else if(amount % 2 == 1) 
        {
            cout << "YES\n";
            for(int i = 1; i < amount; ++i) cout << 1 << " ";
            cout << sum - amount + 1 << "\n";
        } 
        else 
        {
            cout << "YES\n";
            for(int i = 2; i < amount; ++i) cout << 1 << " ";
            cout << (sum - amount + 2)/2 << " " << (sum - amount + 2)/2 << "\n";
        }
    }
}
