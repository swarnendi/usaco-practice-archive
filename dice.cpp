#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    if (cin >> t) 
    {
        while (t--) 
        {
            vector<int> a(4);
            vector<int> b(4);

            for (int i = 0; i < 4; i++) 
            {
                cin >> a[i];
            }

            for (int i = 0; i < 4; i++) 
            {
                cin >> b[i];
            }

            int ab_wins = 0;
            int ba_wins = 0;

            for (int i = 0; i < 4; i++) 
            {
                for (int j = 0; j < 4; j++) 
                {
                    if (a[i] > b[j]) 
                    {
                        ab_wins++;
                    }
                    else if (b[j] > a[i]) 
                    {
                        ba_wins++;
                    }
                }
            }

            bool a_beats_b = (ab_wins > ba_wins);
            bool b_beats_a = (ba_wins > ab_wins);
            bool possible = false;

            for (int d1 = 1; d1 <= 10; d1++) 
            {
                for (int d2 = 1; d2 <= 10; d2++) 
                {
                    for (int d3 = 1; d3 <= 10; d3++) 
                    {
                        for (int d4 = 1; d4 <= 10; d4++) 
                        {
                            vector<int> c = {d1, d2, d3, d4};

                            int bc_wins = 0;
                            int cb_wins = 0;
                            int ca_wins = 0;
                            int ac_wins = 0;

                            for (int i = 0; i < 4; i++) 
                            {
                                for (int j = 0; j < 4; j++) 
                                {
                                    if (b[i] > c[j]) 
                                    {
                                        bc_wins++;
                                    }
                                    else if (c[j] > b[i]) 
                                    {
                                        cb_wins++;
                                    }

                                    if (c[i] > a[j]) 
                                    {
                                        ca_wins++;
                                    }
                                    else if (a[j] > c[i]) 
                                    {
                                        ac_wins++;
                                    }
                                }
                            }

                            bool b_beats_c = (bc_wins > cb_wins);
                            bool c_beats_b = (cb_wins > bc_wins);
                            bool c_beats_a = (ca_wins > ac_wins);
                            bool a_beats_c = (ac_wins > ca_wins);

                            if (a_beats_b && b_beats_c && c_beats_a) 
                            {
                                possible = true;
                            }
                            if (b_beats_a && c_beats_b && a_beats_c) 
                            {
                                possible = true;
                            }
                        }
                    }
                }
            }

            if (possible) 
            {
                cout << "yes\n";
            }
            else 
            {
                cout << "no\n";
            }
        }
    }
}
