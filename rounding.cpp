#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        
        long long lower_bound = 45;
        long long upper_bound = 49;
        long long total_bad_numbers = 0;
        
        while (lower_bound <= N) {
            if (N >= upper_bound) {

                total_bad_numbers += (upper_bound - lower_bound + 1);
                
            } else if (N >= lower_bound) {

                total_bad_numbers += (N - lower_bound + 1);
            }
            
            lower_bound = lower_bound * 10 - 5; 
            upper_bound = upper_bound * 10 + 9; 
        }
        
        cout << total_bad_numbers << "\n";
    }
    
    return 0;
}
