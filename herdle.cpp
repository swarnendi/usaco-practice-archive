#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a1, a2, a3;

    if (cin >> a1 >> a2 >> a3) 
    {
        string g1, g2, g3;
        cin >> g1 >> g2 >> g3;

        string ca = a1 + a2 + a3;
        string cg = g1 + g2 + g3;

        int count_green = 0;
        int count_yellow = 0;

        vector<int> ans_count(26);
        vector<int> guess_count(26);

        for (char c : ca) 
        {
            ans_count[c - 'A']++;
        }

        for (char c : cg) 
        {
            guess_count[c - 'A']++;
        }

        for (int i = 0; i < 9; i++) 
        {
            if (ca[i] == cg[i]) 
            {
                count_green++;
                ans_count[ca[i] - 'A']--;
                guess_count[cg[i] - 'A']--;
            }
        }

        
        for (int i = 0; i < 26; i++) 
        {
            count_yellow += min(guess_count[i], ans_count[i]);
        }

        cout << count_green << "\n" << count_yellow << "\n";
    }
}