#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int amount;
    cin >> amount;
    vector<int> vec(amount);
    for (int i = 0; i < amount; i++) cin >> vec[i];

    int count = 0;

    for (int l = 0; l < amount; l++) 
    {
        int sum = 0;
        for (int r = l; r < amount; r++) 
        {
            sum += vec[r];
            bool valid = true;
            for (int i = l; i <= r; i++) 
            {
                if (sum % vec[i] == 0) 
                {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
