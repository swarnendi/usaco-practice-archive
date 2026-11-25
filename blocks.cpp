
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> blocks(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> blocks[i];
    }

    while (n--)
    {
        string word;
        cin >> word;

        bool possible = false;

        for (int a = 0; a < 4; a++)
        {
            if (blocks[a].find(word[0]) == string::npos)
                continue;

            if (word.size() == 1)
                possible = true;

            for (int b = 0; b < 4; b++)
            {
                if (a == b || word.size() < 2)
                    continue;

                if (blocks[b].find(word[1]) == string::npos)
                    continue;

                if (word.size() == 2)
                    possible = true;

                for (int c = 0; c < 4; c++)
                {
                    if (a == c || b == c || word.size() < 3)
                        continue;

                    if (blocks[c].find(word[2]) == string::npos)
                        continue;

                    if (word.size() == 3)
                        possible = true;

                    for (int d = 0; d < 4; d++)
                    {
                        if (a == d || b == d || c == d ||
                            word.size() < 4)
                            continue;

                        if (blocks[d].find(word[3]) != string::npos)
                            possible = true;
                    }
                }
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
