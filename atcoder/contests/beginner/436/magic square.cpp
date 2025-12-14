#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> grid;

int main() 
{
    int amount;
    cin >> amount;
    grid.assign(amount, vector<int>(amount, 0));

    int r = 0;
    int c = amount / 2;

    grid[r][c] = 1;

    for(int k = 2; k <= amount * amount; k++) 
    {
        int nr = (r - 1 + amount) % amount;
        int nc = (c + 1) % amount;
        if(grid[nr][nc] == 0) 
        {
            r = nr;
            c = nc;
        } 
        else 
        {
            r = (r + 1) % amount;
        }
        grid[r][c] = k;
    }

    for(int i = 0; i < amount; i++) 
    {
        for(int j = 0; j < amount; j++) 
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
