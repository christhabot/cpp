#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int amountq;
    scanf("%d", &amountq);

    while (amountq--)
    {
        int groups, classes;
        scanf("%d %d", &groups, &classes);

        vector<int> rooms(classes);
        for (int i = 0; i < classes; i++)
            scanf("%d", &rooms[i]);

        sort(rooms.begin(), rooms.end());

        vector<vector<int>> ans(groups, vector<int>(6));

        for (int i = 0; i < groups; i += 2)
        {
            int low = i / 2;
            int high = classes - low - 1;

            if (i + 1 < groups)
            {
                for (int j = 0; j < 6; j++)
                {
                    ans[i][j] = (j % 2 == 0) ? rooms[low] : rooms[high];
                    ans[i+1][j] = (j % 2 == 0) ? rooms[high] : rooms[low];
                }
            }
            else
            {
                for (int j = 0; j < 6; j++)
                    ans[i][j] = (j % 2 == 0) ? rooms[low] : rooms[high];
            }
        }

        for (int i = 0; i < groups; i++)
        {
            for (int j = 0; j < 6; j++)
                printf("%d ", ans[i][j]);
            printf("\n");
        }
    }

    return 0;
}
