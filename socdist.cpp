#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int n;

    if (cin >> n) 
    {
        string s;
        vector<pair<int, int>> available;

        cin >> s;
        int start = -1;

        for (int i = 0; i <= n; ++i) 
        {
            if (i < n && s[i] == '0')
            {
                if (start == -1) 
                { 
                    start = i;
                }
            } 
            else if (start != -1) 
            {
                pair<int, int> p = {start, i - 1};
                available.push_back(p);
                start = -1;
            }
        }

        if (available.size() == 1 && available[0].first == 0 && available[0].second == n - 1) 
        {
            cout << n - 1 << "\n";
            return 0;
        }

        int orig_min = n;
        int prev_one = -1;

        for (int i = 0; i < n; ++i) 
        {
            if (s[i] == '1') 
            {
                if (prev_one != -1) 
                {
                    orig_min = min(orig_min, i - prev_one);
                }
                prev_one = i;
            }
        }

        int left_edge = 0;
        int right_edge = 0;
        vector<int> interior;

        for (int i = 0; i < available.size(); ++i) 
        {
            int len = available[i].second - available[i].first + 1;

            if (available[i].first == 0) 
            {
                left_edge = len;
            } 
            else if (available[i].second == n - 1) 
            {
                right_edge = len;
            } 
            else 
            {
                int left = available[i].first - 1;
                int right = available[i].second + 1;
                interior.push_back(right - left);
            }
        }

        sort(interior.rbegin(), interior.rend());

        int ans = 1;

        if (!interior.empty()) 
        {
            ans = max(ans, interior[0] / 3);
        }

        if (interior.size() >= 2) 
        {
            ans = max(ans, min(interior[0] / 2, interior[1] / 2));
        }

        if (left_edge > 0 && right_edge > 0) 
        {
            ans = max(ans, min(left_edge, right_edge));
        }

        int best_edge = max(left_edge, right_edge);

        if (best_edge > 0 && !interior.empty()) 
        {
            ans = max(ans, min(best_edge, interior[0] / 2));
        }

        if (best_edge > 0) 
        {
            ans = max(ans, best_edge / 2);
        }

        ans = min(ans, orig_min);

        cout << ans << "\n";
    }
}
