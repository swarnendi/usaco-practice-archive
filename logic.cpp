#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<int> group(n);
    vector<int> first_false, last_false;
    
    int g = 0;
    first_false.push_back(n + 1);
    last_false.push_back(-1);

    for (int i = 0; i < n; i += 2)
    {
        group[i] = g;
        if (s[i] == "false")
        {
            first_false[g] = min(first_false[g], i);
            last_false[g] = max(last_false[g], i);
        }
        if (i + 1 < n && s[i + 1] == "or")
        {
            g++;
            first_false.push_back(n + 1);
            last_false.push_back(-1);
        }
    }

    int num_groups = g + 1;
    int first_true_g = num_groups + 1;
    int last_true_g = -1;

    for (int id = 0; id < num_groups; id++)
    {
        if (last_false[id] == -1)
        {
            first_true_g = min(first_true_g, id);
            last_true_g = max(last_true_g, id);
        }
    }

    while (q--)
    {
        int l, r;
        string target;
        cin >> l >> r >> target;
        l--;
        r--;

        int gl = group[l], gr = group[r];

        if (first_true_g < gl || last_true_g > gr)
        {
            cout << (target == "true" ? 'Y' : 'N');
            continue;
        }

        if (target == "false")
        {
            cout << 'Y';
        }
        else
        {
            bool blocked = (first_false[gl] < l) || (last_false[gr] > r);
            cout << (!blocked ? 'Y' : 'N');
        }
    }
    cout << '\n';
    return 0;
}
