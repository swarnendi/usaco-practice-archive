#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int n, k;

    if (cin >> k >> n) 
    {
        vector<vector<int>> all_rankings(k, vector<int>(n));

        for (int i = 0; i < k; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                cin >> all_rankings[i][j];
            }
        }

        vector<vector<int>> pos(n, vector<int>(k));

        for (int i = 0; i < k; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                int num = all_rankings[i][j];
                pos[num - 1][i] = j;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) 
                {
                    continue;
                }

                bool flag = false;

                for (int h = 0; h < k; h++)
                {
                    if (pos[i][h] > pos[j][h]) 
                    {
                        flag = true;
                    }
                }

                if (!flag) 
                {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
}