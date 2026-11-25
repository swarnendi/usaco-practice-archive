#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector<vector<int>> drink(d, vector<int>(3));
    vector<vector<int>> sick(s, vector<int>(2));

    for (int i = 0; i < d; i++) {
        cin >> drink[i][0] >> drink[i][1] >> drink[i][2];
    }

    for (int i = 0; i < s; i++) {
        cin >> sick[i][0] >> sick[i][1];
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        vector<bool> drank(n + 1, false);
        bool possible = true;

        for (int j = 0; j < s; j++) {
            bool found = false;

            for (int k = 0; k < d; k++) {
                if (drink[k][0] == sick[j][0] &&
                    drink[k][1] == i &&
                    drink[k][2] < sick[j][1]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int j = 0; j < d; j++) {
                if (drink[j][1] == i) {
                    drank[drink[j][0]] = true;
                }
            }

            int cnt = 0;

            for (int j = 1; j <= n; j++) {
                if (drank[j]) {
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}