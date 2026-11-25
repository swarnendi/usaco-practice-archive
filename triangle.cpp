#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N;

    if (cin >> N) 
    {
        vector<pair<int, int>> coords(N);

        for (int i = 0; i < N; i++) 
        {
            cin >> coords[i].first >> coords[i].second;
        }

        int ans = INT_MIN;

        for (int i = 0; i < N; i++) {

            for (int j = 0; j < N; j++) {

                for (int k = 0; k < N; k++) {

                    if (coords[i].second == coords[j].second &&
                        coords[i].first == coords[k].first) {

                        int base = abs(coords[i].first - coords[j].first);
                        int height = abs(coords[i].second - coords[k].second);

                        ans = max(ans, base * height);
                    }

                }

            }
            
        }

        cout << ans;
    }
}