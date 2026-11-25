
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    cin >> n >> t;

    vector<pair<long long, long long>> days(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> days[i].first >> days[i].second;
    }

    sort(days.begin(), days.end());

    long long ans = 0;
    long long last = 0;

    for (int i = 0; i < n; i++) 
    {
        long long start = days[i].first;
        long long bales = days[i].second;

        long long available = max(0LL, start - last - 1);
        long long eat = min(bales, available + bales);

        ans += min(bales, max(0LL, start + bales - 1 - last));
        last = max(last, start + bales - 1);
        ans = min(ans, t);
    }

    cout << ans << '\n';
}
