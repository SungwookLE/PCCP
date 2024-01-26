#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    int n;
    string s1, s2;

    for (int i = 0; i < T; ++i)
    {
        map<string, int> wears;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> s1 >> s2;
            wears[s2] += 1; // MAP 자료구조는 int의 value 지정시, 0초기값이 자동으로 들어가 있음, https://velog.io/@kon6443/CC-Map-STL-%EC%B4%88%EA%B8%B0%EA%B0%92-%EC%84%A4%EC%A0%95
        }

        long long answer = 1; // 경우의 수 문제는 long long을 박고 시작해라 (팁)
        for (auto w : wears)
            answer *= w.second + 1;

        answer--;

        cout << answer << "\n";
    }

    return 0;
}