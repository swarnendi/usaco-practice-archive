#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n;

    if (cin >> n)
    {
        vector<pair<int, string>> l = {
            {0, "Bessie"},
            {0, "Elsie"},
            {0, "Daisy"},
            {0, "Gertie"},
            {0, "Annabelle"},
            {0, "Maggie"},
            {0, "Henrietta"}
        };

        for (int i = 0; i < n; i++)
        {
            string cow;
            int amount;

            cin >> cow >> amount;

            for (int i = 0; i < 7; i++)
            {
                if (cow == l[i].second)
                {
                    l[i].first += amount;
                }
            }
        }

        sort(l.rbegin(), l.rend());

        int min_milk = l[6].first;
        int idx = 6;

        while (idx >= 0 && l[idx].first == min_milk)
        {
            idx--;
        }

        if (idx == -1 || (idx - 1 >= 0 && l[idx].first == l[idx - 1].first))
        {
            cout << "Tie\n";
        }
        else
        {
            cout << l[idx].second << "\n";
        }
    }
}
