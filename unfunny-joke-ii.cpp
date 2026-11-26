
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s;
    cin >> s;

    vector<pair<int, int>> gates(26, {-1, -1});

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (gates[c - 'A'].first != -1)
        {
            gates[c - 'A'].second = i;
        }
        else
        {
            gates[c - 'A'].first = i;
        }
    }

    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            auto [a, b] = gates[i];
            auto [c, d] = gates[j];

            ans += (a < c && c < b && b < d) ||
                   (c < a && a < d && d < b);
        }
    }

    cout << ans << "\n";
}
