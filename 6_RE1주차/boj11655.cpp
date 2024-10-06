#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
    getline(cin, S);

    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] >= 'a' && S[i] <= 'z')
        {
            int res = S[i] - 'a';
            int n = (res + 13) % 26;
            cout << (char)('a' + n);
        }
        else if (S[i] >= 'A' && S[i] <= 'Z')
        {
            int res = S[i] - 'A';
            int n = (res + 13) % 26;
            cout << (char)('A' + n);
        }
        else
        {
            cout << S[i];
        }
    }

    return 0;
}