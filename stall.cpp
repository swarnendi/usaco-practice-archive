#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    if (cin >> N) 
    {
        vector<long long> cows(N);
        vector<long long> stalls(N);

        for (int i = 0; i < N; i++) { cin >> cows[i]; }
        for (int i = 0; i < N; i++) { cin >> stalls[i]; }

        sort(cows.rbegin(), cows.rend());

        long long total_ways = 1;

        for (int i = 0; i < N; i++) 
        {
            int valid_ways = 0;

            for (int j = 0; j < N; j++) 
            {
                if (stalls[j] >= cows[i]) 
                {
                    valid_ways++;
                }
            }

            total_ways *= (valid_ways - i);
        }

        cout << total_ways;
    }
}