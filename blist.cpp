#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int N;

    if (cin >> N) 
    {
        vector<int> timeline(1001);
        
        for (int i = 0; i < N; i++) 
        {
            int start, end, bucket;

            cin >> start >> end >> bucket;

            for (int j = start; j < end; j++) 
            {
                timeline[j] += bucket;
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i < 1001; i++) 
        {
            ans = max(ans, timeline[i]);
        }

        cout << ans;
    }
}