#include <bits/stdc++.h>

using namespace std;
int X;
int S = 64;

int main()
{
    cin >> X;
    int cnt = 0;

    if (X == S)
    {
        cnt++;
        X -= S;
    }

    while (X != 0)
    {
        S = S >> 1; // 2로 나누고
        if (S > X)
        { // 버리고
            ;
        }
        else
        { // 유지하고
            if (X >= S)
            {
                cnt++;
                X -= S;
            }
        }
    }

    cout << cnt;

    return 0;
}