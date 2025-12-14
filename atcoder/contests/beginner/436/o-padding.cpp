#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() 
{
    string str;
    int amount;
    cin >> amount;
    cin >> str;
    for(int i = 0; i < amount - str.size(); i++)
    {
        cout << 'o';
    }
    cout << str;
}