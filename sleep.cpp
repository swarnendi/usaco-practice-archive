#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        int ans = n - 1;

        for (int target = total; target >= 1; target--)
        {
            if (total % target != 0)
            {
                continue;
            }

            int sum = 0;
            int groups = 0;
            bool valid = true;

            for (int i = 0; i < n; i++)
            {
                sum += arr[i];

                if (sum == target)
                {
                    groups++;
                    sum = 0;
                }
                else if (sum > target)
                {
                    valid = false;
                    break;
                }
            }

            if (valid && sum == 0)
            {
                ans = n - groups;
                break;
            }
        }

        cout << ans << "\n";
    }
}