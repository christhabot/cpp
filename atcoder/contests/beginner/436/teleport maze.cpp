#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<char>> vec;
vector<vector<bool>> explored;
map<char, vector<pair<int, int>>> tel;
queue<pair<pair<int,int>, int>> q;

int main() {
    int height, width, qff, qfs, curd;
    scanf("%d %d", &height, &width);
    explored.assign(height, vector<bool>(width, false));
    vec.assign(height, vector<char>(width, '.'));
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            scanf(" %c", &vec[i][j]);
            if(vec[i][j] != '.' && vec[i][j] != '#')
            {
                tel[vec[i][j]].push_back({i, j});
            }
        }
    }
    q.push({{0, 0}, 0});
    explored[0][0] = true;

    while(!q.empty())
    {
        auto qf = q.front();
        qff = qf.first.first;
        qfs = qf.first.second;
        curd = qf.second;
        if(qff == height-1 && qfs == width-1)
        {
            printf("%d\n", curd);
            return 0;
        }
        q.pop();

        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i != 0 && j != 0) continue;
                if(i == 0 && j == 0) continue;
                if(qff+i < 0 || qff+i >= height) continue;
                if(qfs+j < 0 || qfs+j >= width) continue;
                if(vec[qff+i][qfs+j] == '#') continue;
                if(explored[qff+i][qfs+j]) continue;
                explored[qff+i][qfs+j] = true;
                q.push({{qff+i, qfs+j},curd+1});
            }
        }

        if(vec[qff][qfs] != '.' && vec[qff][qfs] != '#' && tel.count(vec[qff][qfs]))
        {
            for(auto p : tel[vec[qff][qfs]])
            {
                if(!explored[p.first][p.second])
                {
                    explored[p.first][p.second] = true;
                    q.push({{p.first, p.second},curd+1});
                }
            }
            tel.erase(vec[qff][qfs]);
        }
    }
    printf("-1\n");
}
