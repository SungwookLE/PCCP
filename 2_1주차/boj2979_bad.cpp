#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    pair<int, int> t1, t2, t3;
    cin >> t1.first >> t1.second;
    cin >> t2.first >> t2.second;
    cin >> t3.first >> t3.second;

    int maxN = 100;
    vector<int> ps(maxN + 1, 0);

    int answer = 0;
    for (int i = 1; i < maxN; ++i)
    {

        ps[i] = ps[i - 1];

        if (i == t1.first)
            ps[i] += 1;
        else if (i == t1.second)
            ps[i] -= 1;

        if (i == t2.first)
            ps[i] += 1;
        else if (i == t2.second)
            ps[i] -= 1;

        if (i == t3.first)
            ps[i] += 1;
        else if (i == t3.second)
            ps[i] -= 1;

        switch (ps[i])
        {
        case 1:
            answer += A;
            break;
        case 2:
            answer += B * 2;
            break;
        case 3:
            answer += C * 3;
            break;
        default:
            break;
        }
    }

    cout << answer << "\n";
}