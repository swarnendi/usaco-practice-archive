#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        long long abs_k = abs(k);
        map<long long, vector<long long>> groups;
        
        for (int i = 0; i < n; i++) {
            long long val;
            cin >> val;
            
            long long r = val % abs_k;
            if (r < 0) r += abs_k;
            
            long long step = (val - r) / abs_k;
            groups[r].push_back(step);
        }
        
        long long total_ops = 0;
        
        for (auto& pair : groups) {

            auto& steps = pair.second;
            
            if (k > 0) {

                sort(steps.begin(), steps.end());
                long long last_filled = -1e18;
                
                for (long long step : steps) {

                    if (step <= last_filled) {

                        long long next_available = last_filled + 1;
                        total_ops += (next_available - step);
                        last_filled = next_available;

                    } 
                    else {

                        last_filled = step;

                    }
                }
            } else {

                sort(steps.begin(), steps.end(), greater<long long>());
                long long last_filled = 1e18;
                
                for (long long step : steps) {

                    if (step >= last_filled) 
                    {
                        long long next_available = last_filled - 1;
                        total_ops += (step - next_available);
                        last_filled = next_available;
                    } 
                    else {
                        last_filled = step;
                    }
                }
            }
        }
        
        cout << total_ops << "\n";
    }
    return 0;
}
