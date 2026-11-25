#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string s;

    cin >> N >> s;

    int64_t ans = 0;

    for (int i = 0; i < N; i++)
    {
        int64_t lhs = 0;
        int64_t rhs = 0;

        if (i > 0 && s[i - 1] != s[i])
        {
            lhs++;

            for (int k = i - 2; k >= 0 && s[k] == s[i - 1]; k--)
                lhs++;
        }

        if (i + 1 < N && s[i + 1] != s[i])
        {
            rhs++;

            for (int k = i + 2; k < N && s[k] == s[i + 1]; k++)
                rhs++;
        }

        ans += lhs * rhs;
        ans += max(lhs - 1, (int64_t)0);
        ans += max(rhs - 1, (int64_t)0);
    }

    cout << ans << '\n';
}