#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    if (cin >> t) 
    {

        while (t--) 
        {

            int n;
            cin >> n;

            vector<int> cows(n);
            vector<bool> good(n);

            for (int i = 0; i < n; i++) 
            {
                cin >> cows[i];
                cows[i]--;
                if (i > 0 && cows[i] == cows[i - 1] || i > 1 && cows[i] == cows[i - 2]) 
                {
                    good[cows[i]] = true;
                }
            }

            string vals = "";

            for (int i = 0; i < n; i++) { 
                if (good[i]) { 
                    vals += to_string(i + 1) + " "; 
                } 
            } 

            if (!vals.empty()) {
                vals = vals.substr(0, vals.size() - 1);
                cout << vals << "\n";
            }
            else 
            {
                cout << "-1" << "\n";
            }
        }
    }
}