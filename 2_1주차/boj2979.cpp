#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int a, b;
    vector<int> cstar(100, 0);
    for (int i = 0; i < 3; ++i)
    {
        cin >> a >> b;
        cstar[a] += 1;
        cstar[b] -= 1;
    }

    int answer = 0;
    vector<int> psum(100, 0);
    for (int i = 1; i < 100; ++i)
    {

        psum[i] = psum[i - 1] + cstar[i];

        switch (psum[i])
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
    return 0;
}