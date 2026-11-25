#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;

    if (cin >> n) 
    {

        vector<int> heights(n);

        for (int i = 0; i < n; i++) 
        {
            cin >> heights[i];
        }

        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());

        set<int> distincts;

        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            if (sorted[i] != heights[i]) 
            {
                distincts.insert(heights[i]);
            }
        }

        cout << distincts.size() - 1;

        return 0;
    }

    return 1;
}