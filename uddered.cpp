#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string alph;
    
    if (cin >> alph) 
    {
        string word;
        cin >> word;

        vector<int> indexes(word.length());

        for (int i = 0; i < word.length(); i++) 
        {
            for (int j = 0; j < 26; j++) 
            {
                if (alph[j] == word[i]) 
                {
                    indexes[i] = j + 1;
                }
            }
        }

        int ans = 1;

        for (int i = 0; i < indexes.size() - 1; i++) 
        {
            if (indexes[i + 1] - indexes[i] <= 0) 
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }
}