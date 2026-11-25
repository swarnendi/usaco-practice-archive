#include <bits/stdc++.h>

using namespace std;

int last_visited[2001][2001];

int main() {

    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < 2001; i++) {

        for (int j = 0; j < 2001; j++) {

            last_visited[i][j] = -1;
        }

    }

    int cur_x = 1000;
    int cur_y = 1000;
    int current_time = 0;

    last_visited[cur_x][cur_y] = current_time;
    int min_ans = 1e9;

    for (int i = 0; i < n; i++) {

        char direction;
        int steps;
        cin >> direction >> steps;

        int dx = 0, dy = 0;
        if (direction == 'N') dy = 1;
        else if (direction == 'S') dy = -1;
        else if (direction == 'E') dx = 1;
        else if (direction == 'W') dx = -1;

        for (int s = 0; s < steps; s++) {
            cur_x += dx;
            cur_y += dy;
            current_time++;

            if (last_visited[cur_x][cur_y] != -1) {
                int time_diff = current_time - last_visited[cur_x][cur_y];
                min_ans = min(min_ans, time_diff);
            }

            last_visited[cur_x][cur_y] = current_time;
        }
    }

    if (min_ans == 1e9) {

        cout << -1 << "\n";

    } else {

        cout << min_ans << "\n";
        
    }

    return 0;
}