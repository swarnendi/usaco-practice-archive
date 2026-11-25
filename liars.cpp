#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    if (cin >> N) {

        vector<pair<char, int>> cows(N);

        for (int i = 0; i < N; i++) {

            cin >> cows[i].first >> cows[i].second;
            
        }
        
        int ans = N; 
        
        for (int i = 0; i < N; i++) {

            int p = cows[i].second;
            int current_liars = 0; 
            
            for (int j = 0; j < N; j++) {
                
                if (cows[j].first == 'G' && p < cows[j].second) {

                    current_liars++;

                } 

                else if (cows[j].first == 'L' && p > cows[j].second) {

                    current_liars++;

                }

            }
            
            ans = min(ans, current_liars);

        }

        cout << ans;

    }
}
