#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)) return 0;

    int min_x = min(x1, x3);
    int max_x = max(x2, x4);
    int min_y = min(y1, y3);
    int max_y = max(y2, y4);

    int width = max_x - min_x;
    int height = max_y - min_y;

    int side = max(width, height);

    int ans = side * side; 
    cout << ans << "\n";

    return 0;
}
