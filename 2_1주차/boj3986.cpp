#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N;
    cin >> N;

    string s;
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;

        stack<char> stacker;
        for (int j = 0; j < s.length(); ++j)
        {
            if (!stacker.empty() && stacker.top() == s[j]) // 비어있지 않을 때만 체크하고, 참조하기
                stacker.pop();
            else
                stacker.push(s[j]);
        }

        if (stacker.empty())
            answer += 1;
    }

    cout << answer << "\n";

    return 0;
}